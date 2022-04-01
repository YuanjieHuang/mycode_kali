#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char **argv)
{
	int fd;
	
	if(argc!=4){
		printf("arvc is 4:\nargv1 is device_node ,\nargv2 is cmd,\nargv2 is lednum\n");
	}
	
	if((fd = open(argv[1], O_RDWR|O_NOCTTY|O_NDELAY))<0){
		printf("open %s failed\n",argv[1]);   
		return -1;
	}
	else{
		printf("open %s ok\n",argv[1]); 
		ioctl(fd,atoi(argv[2]),atoi(argv[3]));		
    }
	close(fd);
	return 0;
}
