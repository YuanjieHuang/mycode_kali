#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int a = 100;            //.data 
int main(void)
{
	pid_t pid;
	pid = fork();
	if(pid == 0){	//son
		// sleep(1);
		a = 2000;
		printf("child, a = %d\n", a);
	} else {
		sleep(1);	//保证son先运行
		printf("parent, a = %d\n", a);
	}
	printf("a:%d\n",a+=100);
	return 0;
}
/*
	output:
child, a = 2000
a:2100
parent, a = 100
a:200
*/