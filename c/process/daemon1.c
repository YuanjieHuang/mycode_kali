#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void creat_daemon(void){
	int i;
	int fd0;
	pid_t pid;
	struct sigaction sa;
	umask(0);//设置文件掩码为0
	if(pid=fork()<0){
		printf("child dir error\n");
	}
	else {
		exit(0);//
	}

	setid(0);//设置新的会话
	sa.sa_handler=SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	if(sigaction(SIGCHLD,&sa,NULL)<0){//注册子进程退出忽略信号
		return;
	}
	if(pid=fork()<0){//再次fork，终止父进程保证子进程不是话首进程，保证进程不会受到其他进程的干扰
		printf("fork error!\n");
		return;
	}
	else if(pid!=0){
		exit(0);
	}

	if(chdir("/")<0){//更改工作目录到根目录
		printf("child dir error\n");                                                
		return;
	}
	close(0);
	fd0=open("/dev/null",O_RDWR);//关闭标准输入 ，标准输出，标准错误
	dup2(fd0,1);
	dup2(fd0,2);
}

int main()
{
	creat_daemon();
	while(1){
		sleep(1);

	}

}