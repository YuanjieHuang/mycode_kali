#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <csignal>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using std::cout;
using std::endl;
using std::vector;

const int BUF_SIZE = 1024;

int main(int argc, char *argv[])
{
    cout << "lsl" << endl;

    const char *ip = "127.0.0.1"; //ip
    int port = atoi("8899");            //端口

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

    //监听多个客户端连接
    vector<int> conn_fds;

    //定义select中的fd_set
    fd_set read_fds;
    fd_set exception_fds;
    FD_ZERO(&read_fds); //初始化清除fd_set中的所有位
    FD_ZERO(&exception_fds);

    while (true)
    {
        cout << "Select server:" << endl;
        memset(buffer, 0, BUF_SIZE);
        /*每次调用select前都要重新在read_fds和exception_fds中设置文件描述符conn_fd，因为事件发生之后，文件描述符集合将被内核修改*/
        //设置对服务器/客户端文件描述符监听，重复监听变化
        FD_SET(listen_fd, &read_fds);
        FD_SET(listen_fd, &exception_fds);

        //select复用，在一段指定时间内，监听用户感兴趣的文件描述符上的可读、可写和异常等事件。阻塞等到事件到来
        int max_conn_fd = 0;
        if (conn_fds.size() != 0)
        {
            auto max_iter = std::max_element(conn_fds.begin(), conn_fds.end());
            max_conn_fd = *max_iter;
        }
        ret = select(std::max(0, std::max(listen_fd, max_conn_fd)) + 1, &read_fds, NULL, &exception_fds, NULL);
        if (ret < 0)
        {
            std::cout << "select多路复用失败" << std::endl;
            break;
        }
        //最后时间参数设置为NULL，阻塞等到事件到来，不同的事件有不同的处理方案

        //服务器监听到事件，接受连接
        if (FD_ISSET(listen_fd, &read_fds))
        {
            //客户端tcp连接描述，等待符合格式的连接
            struct sockaddr_in client;
            socklen_t client_addrlength = sizeof(client);
            int conn_fd = accept(listen_fd, (struct sockaddr *)&client, &client_addrlength);
            conn_fds.push_back(conn_fd);
            cout << "Connected! conn_fd:" << conn_fd << endl;
            FD_SET(conn_fd, &read_fds);
        }

        //连接事件队列conn_fds中有事件，遍历扫描
        for (vector<int>::iterator it = conn_fds.begin(); it != conn_fds.end(); it++)
        {
            int conn_fd = *it;
            //普通可读事件
            if (FD_ISSET(conn_fd, &read_fds))
            {
                ret = recv(conn_fd, buffer, sizeof(buffer) - 1, 0);
                if (ret < 0)
                {
                    std::cout << "读取普通数据失败，错误码：" << ret << std::endl;
                    break;
                }
                std::cout << "读取数据：" << buffer << " ret:" << ret << std::endl;
                close(conn_fd);
                it = conn_fds.erase(it);
                it--;
            }
            //对于异常事件，采用带MSG_OOB标志的recv函数读取带外数据
            else if (FD_ISSET(conn_fd, &exception_fds))
            {
                ret = recv(conn_fd, buffer, sizeof(buffer) - 1, MSG_OOB); //MSG_OOB TCP紧急指针标志位
                if (ret < 0)
                {
                    std::cout << "读取紧急数据失败，错误码：" << ret << std::endl;
                    break;
                }
                std::cout << "读取紧急数据：" << buffer << " ret:" << std::endl;
                close(conn_fd);
                it = conn_fds.erase(it);
                it--;
            }
        }
    }
    close(listen_fd);
    return 0;
}
