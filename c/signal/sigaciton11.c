#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
void pr_mask(const char *str)
{
    sigset_t    sigset;
    int        errno_save;
    errno_save = errno;    /* we can be called by signal handlers */
    if (sigprocmask(0, NULL, &sigset) < 0)
        perror("sigprocmask error");
    printf("%s", str);
    if (sigismember(&sigset, SIGINT))    printf("SIGINT ");
    if (sigismember(&sigset, SIGQUIT))    printf("SIGQUIT ");
    if (sigismember(&sigset, SIGUSR1))    printf("SIGUSR1 ");
    if (sigismember(&sigset, SIGALRM))    printf("SIGALRM ");
    /* remaining signals can go here */
    printf("\n");
    errno = errno_save;
}
int main()
{
    struct sigaction newact,oldact;
    /* 设置信号忽略 */
    newact.sa_handler = SIG_IGN; //这个地方也可以是函数
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    int count = 0;
    pid_t pid = 0;
    sigaction(SIGINT,&newact,&oldact);//原来的备份到oldact里面
    pid = fork();
    if(pid == 0)
    {
        while(1)
        {
            printf("I'm child gaga.......\n");
            sleep(1);
        }
        return 0;
    }
    while(1)
    {
        if(count++ > 3)
        {
            sigaction(SIGINT,&oldact,NULL);  //备份回来
            printf("pid = %d\n",pid);
            kill(pid,SIGKILL); //父进程发信号，来杀死子进程
        }
        printf("I am father .......... hahaha\n");
        sleep(1);
    }
    return 0;
}