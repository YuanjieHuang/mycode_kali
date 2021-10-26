#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <stdio.h>
#include <sys/reg.h>


int main()
{
    pid_t child;
    long orig_rax = 0;
   

    child = fork();

    if (child==0){
        ptrace(PTRACE_TRACEME,0,NULL,NULL);//子进程告诉内核，让别人跟踪他
        execl("/bin/ls","ls",NULL);
    } else{
        wait(NULL);//wait函数等待内核通知，子进程结束后就会收到
        orig_rax = ptrace(PTRACE_PEEKUSER,child,4*ORIG_RAX,NULL);//读取子进程运行时eax寄存器的值
        perror("ptrace");
        printf("The child made a system call %ld\n",orig_rax);
        ptrace(PTRACE_CONT,child,NULL,NULL);//让子进程继续运行
    }
    return 0;

}
#if 0
void my_ptrace()
{
  pid_t pid;
  switch(pid = fork())
    {
    case -1:
        return -1;
    case 0: //子进程
        ptrace(PTRACE_TRACEME,0,NULL,NULL);
        execl("./HelloWorld", "HelloWorld", NULL);
    default: //父进程
        wait(&val); //等待并记录execve
        if(WIFEXITED(val))
            return 0;
        syscallID=ptrace(PTRACE_PEEKUSER, pid, ORIG_EAX*4, NULL);
        printf("Process executed system call ID = %ld\n",syscallID);
        ptrace(PTRACE_SYSCALL,pid,NULL,NULL);
        while(1)
        {
            wait(&val); //等待信号
            if(WIFEXITED(val)) //判断子进程是否退出
                return 0;
            if(flag==0) //第一次(进入系统调用)，获取系统调用的参数
            {
                syscallID=ptrace(PTRACE_PEEKUSER, pid, ORIG_EAX*4, NULL);
                printf("Process executed system call ID = %ld ",syscallID);
                flag=1;
            }
            else //第二次(退出系统调用)，获取系统调用的返回值
            {
                returnValue=ptrace(PTRACE_PEEKUSER, pid, EAX*4, NULL);
                printf("with return value= %ld\n", returnValue);
                flag=0;
            }
            ptrace(PTRACE_SYSCALL,pid,NULL,NULL);
        }
    }
}
#endif