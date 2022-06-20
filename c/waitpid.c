#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
void catchSig(int sig)
{
    printf("get a sig: %d,pid: %d\n", sig, getpid());
}
int main()
{
    signal(SIGCHLD,catchSig);//catch SIGCHLD(17)
    pid_t id=fork();//create child process
    if(id == 0)
    {
        //child
        printf("i am child,quit!my pid is %d\n",getpid());
        exit(1);
    }
    else
    {
        //father
        waitpid(id,NULL,0);//wait child                                     
    }
return 0;
}