#include <stdio.h>                                  
#include <stdlib.h>                                 
#include <string.h>                                 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc,char *argv[])                     
{                                                   
	int ret = 0;
	char buf[1024];
	memset(buf,0,sizeof(buf));
	ret = open("./fifo",O_RDONLY);
	if(0 > ret)
	{
		printf("line:%d\n",__LINE__);
		perror("mkfifo");exit(-1);
	}	                          
	else
	{
		read(ret,buf,sizeof(buf));
		printf("read buf is:%s\n",buf);
	}	               
	close(ret);
	return 0;                                   
}         