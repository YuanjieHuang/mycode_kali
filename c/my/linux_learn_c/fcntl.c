#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#define MSG_TRY "try again\n"
int my_fcntl()
{
    pid_t pid;
    //以追加的形式打开文件
    int fd = fd = open("test.txt", O_TRUNC | O_RDWR | O_APPEND | O_CREAT, 0777);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }
    printf("fd = %d\n", fd);
    fcntl(fd, F_SETFD, 0);//关闭fd的close-on-exec标志
    write(fd, "hello c program\n", strlen("hello c program!\n"));
    pid = fork();
    if(pid < 0)
    {
            perror("fork");
            return -1;
    }
    if(pid == 0)
    {
        printf("fd = %d\n", fd);
        int ret = execl("./main", "./main", (char *)&fd, NULL);
        if(ret < 0)
        {
            perror("execl");
            exit(-1);
        }
        exit(0);
    }
    wait(NULL);
    write(fd, "hello c++ program!\n", strlen("hello c++ program!\n"));
    close(fd);
    return 0;
}
int test_fcntl(int argc, char *argv[])
{
	int fd = (int)(*argv[1]);
	printf("fd:%d\n",fd);
	int ret = write(fd, "hello linux\n", strlen("hello linux\n"));
	if(ret<0)
	{
		perror("write");
		return -1;
	}
	close(fd);
	return 0;
}
int main(void)
{
	char buf[10] = "fcntl tset";
	int flags, n;
	flags = fcntl(STDIN_FILENO, F_GETFL); //获取stdin属性信息
	if(flags == -1){
		perror("fcntl error");
		exit(1);
	}
	flags |= O_NONBLOCK;
	int ret = fcntl(STDIN_FILENO, F_SETFL, flags);
	if(ret == -1){
		perror("fcntl error");
		exit(1);
	}
tryagain:
	n = read(STDIN_FILENO, buf, 10);
	if(n < 0){
		if(errno != EAGAIN){		
			perror("read /dev/tty");
			exit(1);
		}
		sleep(3);
		write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
		goto tryagain;
	}
	write(STDOUT_FILENO, buf, n);
	return 0;
}
