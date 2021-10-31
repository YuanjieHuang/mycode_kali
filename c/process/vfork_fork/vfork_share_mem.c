#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int a = 10;
int main(int argc, char *argv[])
{
	pid_t pid;
	int b = 20;
	pid = vfork();	// 创建进程
	if(pid < 0){ // 出错
		perror("vfork");
	}
	if(0 == pid){ // 子进程
		a = 100, b = 200;
		printf("son: a = %d, b = %d\n", a, b);
		_exit(0); // 退出子进程，必须
	}else if(pid > 0){ // 父进程
		printf("father: a = %d, b = %d\n", a, b);
	}
	return 0;
}
// vfork() 保证子进程先运行，在它调用 exec（进程替换） 或 exit（退出进程）之后父进程才可能被调度运行。如果子进程没有调用 exec, exit, 程序则会导致死锁