#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <ctype.h>
#include <unistd.h>

#include "wrap.h"

#define MAXLINE 8192
#define SERV_PORT 8000

void do_sigchild(int num)
{
    while (waitpid(0, NULL, WNOHANG) > 0)
        ;
}

int main(void)
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i, n;
    pid_t pid;
    struct sigaction newact;

    newact.sa_handler = do_sigchild;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
//     在linux系统中，父进程通常会接收子进程SIGCHLD信号监测子进程是否退出，通过waitpid函数对子进程进行回收。
//     但是实际应用过程中waitpid使用不当，会出现子进程成为僵尸进程。原因在于，SIGCHLD信号是不可靠信号，
//     不可靠信号在Linux中不进行排队，只是放到一个缓冲区，一旦该信号解除阻塞则会立即被发送一次(不可靠信号会丢失)。
// 任何一个子进程（init除外）在exit()之后，并非马上就消失，而是留下一个称为僵尸进程(Zombie)的数据结构，等待父进程回收。
// 由于SIGCHLD信号的丢失，如果父进程不进行回收处理，子进程就会一直处于僵尸状态。
// 解决的办法有两个，一是在信号处理函数中，以非阻塞的方式调用waitpid，使用while循环，
// 直到waitpid回收完所有等待回收的子进程。如下所示：

    sigaction(SIGCHLD, &newact, NULL);    //建立信号，处理子进程退出

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    // int opt = 1;
    //setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));    //端口复用

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    Listen(listenfd, 20);

    printf("Accepting connections ...\n");
    while (1) {
        cliaddr_len = sizeof(cliaddr);
        connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
        pid = fork();
        if (pid == 0) {
            Close(listenfd);
            while (1) {
                n = Read(connfd, buf, MAXLINE);
                if (n == 0) {
                    printf("the other side has been closed.\n");
                    break;
                }
                printf("received from %s at PORT %d\n",
                        inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),ntohs(cliaddr.sin_port));
                for (i = 0; i < n; i++)
                    buf[i] = toupper(buf[i]);
                Write(STDOUT_FILENO, buf, n);
                Write(connfd, buf, n);
            }
            Close(connfd);
            return 0;
        } else if (pid > 0) {
            Close(connfd);
        }  else
            perr_exit("fork");
    }
    return 0;
}