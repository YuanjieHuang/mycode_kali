#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("========================\n");
    char *argvv[] = {"ls", "-l", "-F",  "-a", NULL};
    pid_t pid = fork();
    if (pid == 0) {
        // execl("/bin/ls", "ls", "-l", "-F", "-a", NULL);
        // perror("execl");
        execv("/bin/ls", argvv);
        perror("execv");
        exit(1);
    } else if (pid > 0) {
        sleep(1);
        printf("parent\n");
    }
    return 0;
}
