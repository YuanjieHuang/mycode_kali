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

