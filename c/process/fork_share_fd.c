/* 
 *父子进程共享打开的文件描述符------使用文件完成进程间通信.
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(void)
{
    int fd1, fd2; 
    pid_t pid,child_pid,parent_pid;
    char buf[1024];
    char *str = "---------test for shared fd in parent child process-----\n";
    printf("main begin\n");
    pid = fork();
    if (pid < 0) {
        perror("fork error");
        exit(1);
    } else if (pid == 0) {
        fd1 = open("test.txt", O_RDWR|O_CREAT);
        if (fd1 < 0) {
            perror("open error");
            exit(1);
        }
        write(fd1, str, strlen(str));
        child_pid = getpid();
        printf("child %d wrote over...\n",child_pid|O_CREAT);
    } else {
        fd2 = open("test.txt", O_RDWR);
        if (fd2 < 0) {
            perror("open error");
            exit(1);
        }
        sleep(1);                   //保证子进程写入数据
        int len = read(fd2, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, len);
        printf("parent %d read over...\n",getpid());
        wait(NULL);
    }

    return 0;
}
