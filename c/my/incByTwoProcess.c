/*
 *父子进程交替数数。
 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t pid;
int global;//copy to write

void sig_handler_p(int sig) //parent 
{
	static int i = 1;
	printf("global:%d pid = %d, I'm father\t%d\n", global, getpid(), i);
	sleep(1);
	i += 2;
	global++;
	kill(pid, SIGUSR1);     //为避免竞态条件出现,应该在捕捉函数内完成数数及信号发送.
}

void sig_handler_c(int sig) //child
{
	static int i = 2;
	printf("global:%d pid = %d, I am child\t%d\n", global, getpid(), i);
	sleep(1);
	i += 2;
	global += 3;
	kill(getppid(), SIGUSR2);
}

int main(void)
{
	int local = 0;
	struct sigaction newact_p, oldact_p;        //父进程使用
	struct sigaction newact_c, oldact_c;        //子进程使用

	//子进程响应SIGUSR1
	newact_c.sa_handler = sig_handler_c;
	sigemptyset(&newact_c.sa_mask);
	newact_c.sa_flags = 0;
	sigaction(SIGUSR1, &newact_c, &oldact_c);

	//父进程响应SIGUSR2
	newact_p.sa_handler = sig_handler_p;
	sigemptyset(&newact_p.sa_mask);
	newact_p.sa_flags = 0;
	newact_p.sa_flags |= SA_RESTART;            //多加这一行可以将被信号打断的系统调用重启。
	sigaction(SIGUSR2, &newact_p, &oldact_p);
	global = 1;
	pid = fork();

	if (pid == 0) {					
		while (1)
		{
			// printf("child local:%d\n",local++);
		}
	} else {
		// printf("prant local:%d\n",local++);						
		raise(SIGUSR2);
		if (wait(NULL)) {			
			perror("wait error");
		}
	}
	
	return 0;
}
