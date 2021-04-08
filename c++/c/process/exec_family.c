if (execl("/bin/ls", "ls", "-a", "-l", NULL) < 0)
{
	perror ("execl");
}

if (execlp("ls", "ls', "-a", "-l", NULL) < 0)
{
	perror("execlp");
}

#include <unistd.h>
int execv(const char *path, char *const argv[]);
int execv(const char *file, char *const argv[]);
arg...封装成指针数组的形式。

char *argv[] = {"ls", "-a", "-l", NULL}

if(execv("/bin/ls", arg) < 0){}
if(execvp("ls", arg) < 0 ){}

#include <stdlib.h>
int system(const char *command);

