#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#define N 5
int main(void)
{
	int i ,j = 0;				//默认创建5个子进程
    printf("j:%d\n",j++);
	for(i = 0; i < N; i++)	//出口1,父进程专用出口
		if(fork() == 0)
			break;			//出口2,子进程出口,i不自增
    printf("i:%d\n",i);
    if (i == 4) {
        sleep(1);
        printf("-----------child ---pid = %d, ppid = %d\n", getpid(), getppid());
        kill(getppid(), SIGKILL);
    } else if (i == N) {
        printf("I am parent, pid = %d\n", getpid());
        while(1);
    }
	return 0;
}
