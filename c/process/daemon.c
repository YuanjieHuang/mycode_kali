// 创建守护进程，每隔1s将系统时间写入文件time.log
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
int main()
{
	pid_t pid;
	FILE *fp;
	time_t t;
	int i;
	
	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid > 0)
	{
		exit(0);
	}
	
	setsid();
	umask(0);
	chdir("/tmp");
	for (i=0;i<getdtablesize();i++)
	{
		close(i);
	}
	if((fp = fopen("time.log", "a")) == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	
	while(1)
	{
		time(&t);
		fprintf(fp, "%s", ctime(&t));
		fflush(fp);
		sleep(1);
    }


    if (fork() != 0) {
        exit(0);
    }
    setsid();
    if (fork() != 0) {
        exit(0);
    }

    close(0);
    close(1);
    close(2);
    open("/dev/null", O_RDWR);
    dup(0);
    dup(0);
    return 0;
}