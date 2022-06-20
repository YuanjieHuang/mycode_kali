#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <csignal>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <poll.h>
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

    int ret = bind(listen_fd, (struct sockaddr *)&address, sizeof(address));
    assert(ret != -1);

    int backlog = 5; //监听队列长度
    ret = listen(listen_fd, backlog);
    assert(ret != -1);

    //----------------------------------------------------------------

    //接受信息，select复用
    char buffer[BUF_SIZE];

    //poll监听多个客户端
    int max_link = 6;
    struct pollfd pollfds[max_link];
    //监听连接事件
    pollfds[0].fd = listen_fd;
    pollfds[0].events = POLLRDNORM;
    for (int i = 1; i < max_link; i++)
    {
        pollfds[i].fd = -1;
        pollfds[i].events = POLLRDNORM;
    }
    int link_count = 1; //连接数量，目前只有连接符在监听

    while (true)
    {
        cout << "Poll server:" << endl;
        memset(buffer, 0, BUF_SIZE);
        //poll多路复用-1代表阻塞等待事件到来，-1阻塞
        ret = poll(pollfds, link_count, -1);
        if (ret < 0)
        {
            std::cout << "poll多路复用失败" << std::endl;
            break;
        }
        //服务器监听到事件，接受连接
        if (pollfds[0].revents & pollfds[0].events)
        {
            //客户端tcp连接描述，等待符合格式的连接
            struct sockaddr_in client;
            socklen_t client_addrlength = sizeof(client);
            int conn_fd = accept(listen_fd, (struct sockaddr *)&client, &client_addrlength);
            struct pollfd conn;
            conn.fd = conn_fd;
            conn.events = POLLRDNORM;
            pollfds[link_count++] = conn;
            cout << "Connected! conn_fd:" << conn_fd << endl;
        }

        //连接事件队列client中有事件，遍历扫描
        for (int i = 1; i < max_link; i++)
        {
            if (pollfds[i].fd > 0)
            {
                if (pollfds[i].revents & pollfds[i].events)
                {
                    ret = recv(pollfds[i].fd, buffer, sizeof(buffer) - 1, 0);
                    if (ret < 0)
                    {
                        std::cout << "读取普通数据失败，错误码：" << ret << std::endl;
                        break;
                    }
                    std::cout << "读取数据：" << buffer << " ret:" << ret << std::endl;
                    close(pollfds[i].fd);
                    pollfds[i].fd = -1;
                    link_count--;
                }
            }
        }
    }
    close(listen_fd);
    return 0;
}
