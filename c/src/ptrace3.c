#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <sys/syscall.h>
#include <stdio.h>

int main(){

    pid_t child;
    long orig_eax,eax;
    long params[3];
    int status;
    int insyscall = 0;
    struct user_regs_struct regs;
    child = fork();

    if (child==0){
        ptrace(PTRACE_TRACEME,0,NULL,NULL);
        execl("/bin/ls","ls",NULL);
    } else{
        while (1){
            wait(&status);
            if (WIFEXITED(status))/*wait函数使用status变量来检查子进程是否已退出。它是用来判断子进程是被ptrace暂停掉还是已经运行结束并退出。*/
                break;
            orig_eax = ptrace(PTRACE_PEEKUSER,child,4*ORIG_RAX,NULL);/*PTRACE_PEEKUSER来察看write系统调用的参数*/
            if (orig_eax==SYS_write){
                if (insyscall==0){
                    insyscall = 1;
                    ptrace(PTRACE_GETREGS,child,NULL,&regs);/*通过将PTRACE_PEEKUSER作为ptrace 的第一个参数进行调用，可以取得与子进程相关的寄存器值。*/

                    printf("Write called with %ld,%ld,%ld\n",regs.rbx,regs.rcx,regs.rdx);


                } else{
                /*说明程序已经退出*/
                    eax = ptrace(PTRACE_PEEKUSER,child,4*RAX,NULL);
                    printf("Write returned with %ld\n",eax);/*返回值保存在eax寄存器*/
                    insyscall = 0;
                }
            }
            ptrace(PTRACE_SYSCALL,child,NULL,NULL);/*使用PTRACE_SYSCALL作为ptrace的第一个参数，使内核在子进程做出系统调用或者准备退出的时候暂停它。*/
        }

    }
    return 0;
}

