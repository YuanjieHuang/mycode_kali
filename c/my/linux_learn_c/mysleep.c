#include <unistd.h>
#include <signal.h>
#include <stdio.h>
void sig_alrm(int signo)
{
    /* nothing to do */
}
unsigned int mysleep(unsigned int nsecs)
{
    struct sigaction newact, oldact;
    unsigned int unslept;
    newact.sa_handler = sig_alrm;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    sigaction(SIGALRM, &newact, &oldact);
    alarm(nsecs);  //1 seconds      SIGALRM ---> 终止进程 
    pause();
    unslept = alarm(0);
    sigaction(SIGALRM, &oldact, NULL);
    return unslept;
}
static unsigned int ret=0, i=0;
int main(void)
{
    while(1){
        mysleep(1);
        printf("ret:%d Two seconds passed i:%d\n",ret, ++i);
    }
    return 0;
}
