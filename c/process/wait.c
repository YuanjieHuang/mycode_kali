#if 0
pid_t waitpid(pid_t pid, int *status, int option);
成功是返回回收的子进程的pid或0（0表示该子进程还没结束）；失败是返回EOF。

waitpid(pid, &status, 0);
waitpid(pid, &status, WNOHANG)；
waitpid(-1, &status, 0);等价于wait(&status);   -1表示任意一个子进程。
waitpid(-1, &status, WNOHANG):
#endif

#include <unistd.h>


int status;
pid_t pid;
if((pid == fork()) < 0)
{
	perror("fork");
	exit(-1);
}

else if(pid ==0)
{
	sleep(1);
	exit(2);
}
else
{
	wait(&status);
	printf("%x\n", status);
}

