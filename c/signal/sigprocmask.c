// 2）一个保护临界区代码的错误实例：(sigprocmask()和pause()实现)
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
void handler(int sig)    //信号处理函数的实现
{
   printf("SIGINT sig\n");
}
int main()
{
    sigset_t newSig,old;
    struct sigaction act;
    act.sa_handler = handler;  //信号处理函数handler
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGINT, &act, 0);  //准备捕捉SIGINT信号
    sigemptyset(&newSig);
    sigaddset(&newSig, SIGINT);
    sigprocmask(SIG_BLOCK, &newSig, &old);  //将SIGINT信号阻塞，同时保存当前信号集
    printf("Blocked\n");
    sigprocmask(SIG_SETMASK, &old, NULL);  //取消阻塞
    pause();  //让进程暂停直到信号出现
    return 0;
}
// 上面实例的问题是：本来期望pause()之后，来SIGINT信号，可以结束程序；可是，如果当“取消阻塞”和“pause”之间，正好来了SIGINT信号，结果程序因为pause的原因会一直挂起。。。
// 解决的方式，当然是sigsuspend()函数了。