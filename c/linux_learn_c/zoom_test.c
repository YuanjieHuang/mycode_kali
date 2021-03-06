#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid, wpid;
    pid = fork();
    
    int status;

    if (pid == 0) {
            printf("---child, my parent= %d, going to sleep 10s\n", getppid());
            sleep(20);
            printf("-------------child die--------------\n");
    } else if (pid > 0) {
        while (1) {
            printf("ppid:%d\n",getppid());
            wpid = wait(&status);
            if (wpid == -1) {
                perror("wait err");
                exit(1);
            }
            printf("I am parent, pid = %d, myson = %d\n", getpid(), pid);
            sleep(1);
        }
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}
