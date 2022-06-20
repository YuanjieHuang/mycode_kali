#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <csignal>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/epoll.h>
#include <iostream>

using std::cout;
using std::endl;

const int BUF_SIZE = 1024;

int main(int argc, char *argv[])
{
    const char *ip = "127.0.0.1"; //ip
    int port = atoi("8899");      //端口

    /*创建一个IPv4 socket地址，主要设置ip和端口信息*/
    struct sockaddr_in address;
    bzero(&address, sizeof(address));          //清空地址
    address.sin_family = AF_INET;              //ipv4
    inet_pton(AF_INET, ip, &address.sin_addr); //ip转换
    address.sin_port = htons(port);            //端口

    //创建socket，ipv4，字符流（tcp）
    int listen_fd = socket(PF_INET, SOCK_STREAM, 0);
    assert(listen_fd >= 0);

    //命名Socket / 绑定Sock
    int ret = bind(listen_fd, (struct sockaddr *)&address, sizeof(address));
    assert(ret != -1);

    int backlog = 5; //监听队列长度
    //监听Socket
    ret = listen(listen_fd, backlog);
    assert(ret != -1);

    //----------------------------------------------------------------

    //接受信息，select复用
    char buffer[BUF_SIZE];

    //epoll监听多个客户端
    int epoll_fd = epoll_create(200);
    int max_link = 6;
    //内核会把已经就绪的事件副本传递给epoll_events，因此每次的epoll_events都会不同
    struct epoll_event epoll_events[max_link];
    //监听连接事件
    struct epoll_event ev;
    ev.data.fd = listen_fd;
    ev.events = EPOLLIN;

    //加入事件
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &ev);

    while (true)
    {
        cout << "epoll server:" << endl;
        memset(buffer, 0, BUF_SIZE);
        //epoll多路复用-1代表阻塞等待事件到来，-1阻塞
        //内核会把已经就绪的事件副本传递给epoll_events
        ret = epoll_wait(epoll_fd, epoll_events, max_link, -1);
        if (ret < 0)
        {
            std::cout << "epoll多路复用失败" << std::endl;
            break;
        }
        //只返回已有事件的socket
        for (int i = 0; i < ret; i++)
        {
            //服务器监听到事件，接受连接，必有事件
            if (epoll_events[i].data.fd == listen_fd)
            {
                //客户端tcp连接描述，等待符合格式的连接
                struct sockaddr_in client;
                socklen_t client_addrlength = sizeof(client);
                int conn_fd = accept(listen_fd, (struct sockaddr *)&client, &client_addrlength);
                struct epoll_event conn;
                conn.data.fd = conn_fd;
                conn.events = EPOLLIN;
                //增加新的监听
                epoll_ctl(epoll_fd, EPOLL_CTL_ADD, conn_fd, &conn);
                cout << "客户端连接成功conn_fd:" << conn_fd << endl;
            }
            //其余事件，遍历扫描
            else if (epoll_events[i].events & EPOLLIN)
            {
                ret = recv(epoll_events[i].data.fd, buffer, sizeof(buffer) - 1, 0);
                if (ret < 0)
                {
                    std::cout << "读取普通数据失败，错误码：" << ret << std::endl;
                    break;
                }
                std::cout << "读取数据：" << buffer << " ret:" << ret << std::endl;
                //不再监听--此处可以监听关闭socket事件，这里简化
                close(epoll_events[i].data.fd);
                epoll_ctl(epoll_fd, EPOLL_CTL_DEL, epoll_events[i].data.fd, &epoll_events[i]);
            }
        }
    }

    //关闭Socket
    close(listen_fd);

    return 0;
}
