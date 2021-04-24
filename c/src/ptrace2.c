#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <stdio.h>
#include <syscall.h>

int main()
{
    pid_t child;
    long orig_rax, rax;
    long params[3];
    int status;
    int insyscall =0;
    child = fork();
    if(child ==0){
        ptrace(PTRACE_TRACEME,0, NULL, NULL);//子进程告诉内核让别人来跟踪
        execl("/bin/ls","ls", NULL);
    } else {
        while(1) {
            /*wait函数使用status变量来检查子进程是否已退出。它是用来判断子进程是被ptrace暂停掉还是已经运行结束并退出。
            有一组宏可以通过status的值来判断进程的状态，比如WIFEXITED等*/
            wait(&status);
            printf("status:%d, WIFEXITED(status):%d\n",status,WIFEXITED(status));
            if(WIFEXITED(status))
                break;
            orig_rax = ptrace(PTRACE_PEEKUSER,child,4* ORIG_RAX, NULL);
            perror("ptrace");
            printf("orig_rax:%d\n",orig_rax);
            if(orig_rax == SYS_write) {    //如果是SYS_write调用
                if(insyscall == 0) {
                    /* Syscall entry */
                    insyscall =1;
                    //获取参数
                    params[0]= ptrace(PTRACE_PEEKUSER,
                                      child,4* RBX,
                                      NULL);
                    params[1]= ptrace(PTRACE_PEEKUSER,
                                      child,4* RCX,
                                      NULL);
                    params[2]= ptrace(PTRACE_PEEKUSER,
                                      child,4* RDX,
                                      NULL);
                    printf("\033[31mWrite called with "
                           "%ld, %ld, %ld\n\033[0m",
                           params[0], params[1],
                           params[2]);
                } else {/* Syscall exit */
                    rax = ptrace(PTRACE_PEEKUSER,
                                 child,4* RAX, NULL);
                    printf("Write returned "
                           "with %ld\n", rax);
                    insyscall =0;
                }
            }
            ptrace(PTRACE_SYSCALL,
                   child, NULL, NULL); /*使用PTRACE_SYSCALL作为ptrace的第一个参数，使内核在子进程做出系统调用或者准备退出的时候暂停它。*/
        }
    }
    return 0;
}