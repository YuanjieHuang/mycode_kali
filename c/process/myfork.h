#include <unistd.h>
/*
 pid_t fork(void);
 返回-1,失败；成功时父进程返回子进程的进程号，子进程返回0.
 * */
pid_t pid;
if((pid = fork() < 0)
{
	perror("fork");
	return -1;
}

else if (pid == 0)
{
	printf("child process : my pid is %d\n", getpid());
}

else
{
	printf("parent process : my pid is %d\n", getpid());
}


//init进程是linux启动后的第一个用户态进程，负责回收孤儿进程。
//父进程先结束：1.子成孤儿；2.子进程变成后台进程。
//子进程先结束：1.父没及时回收PCB，子进程变成僵尸进程。
//
//子进程从何处开始运行？
//stdlib.h-->void

