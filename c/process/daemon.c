#if 0
守护进程：
通常在系统启动时运行，系统关闭时结束。
linux以会话session


create daemon:
1.create son proces,exit parent process

if (fork() > 0)
{
	exit(0);
}

2.son process create a new session

if(setid() < 0)
{
	exit(-1);
}

3.change current work directory

chdir("/");
chdir("/tmp");

4.reset umask

if (umask(0) < 0)
{
	exit(-1);
}//the mask only affects the process.

5. close file describle sysmble

int i;
for(i =0; i<getdtablesize();i++)
{
	close(i);
}

示例1.
创建守护进程，每隔1s将系统时间写入文件time.log
#endif

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
	
	setid();
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
  return true;
}