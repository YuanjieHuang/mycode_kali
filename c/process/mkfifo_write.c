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
	char WtoR[] = "frist execute W,next execute R";
	ret = mkfifo("./fifo",0666);
	if(0 != ret)
	{
		perror("mkfifo"),exit(-1);
	}	           
	printf("line:%d\n",__LINE__);
	ret = open("./fifo",O_WRONLY);
	if(0 >= ret)
	{
		perror("open");exit(-1);
	}		                    
	else
	{
		write(ret,WtoR,sizeof(WtoR));
	}                     
	return 0;                                   
}  