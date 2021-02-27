#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork();
    int i = 0;
    if (pid > 0) {
        printf("parnet, getpgrp = %d\n", getpgrp());
        printf("parnet, getpgid() = %d\n", getpgid(getpid()));

        setpgid(getpid(), getppid());
        printf("parnet, getpgid() = %d\n", getpgid(getpid()));

        wait(NULL);
        printf("After wait\n");

    } else {
        printf("child, getpgrp = %d\n", getpgrp());
        printf("child, getpgid() = %d\n", getpgid(getpid()));
        sleep(1);
        printf("---after set ---child, getpgid() = %d\n", getpgid(getpid()));
    }
    printf("i:%d\n", i++);
    return 0;
}
