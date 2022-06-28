#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>		  /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <netdb.h>  
#include <errno.h>
#include <unistd.h>
 
extern int errno;
 
int main()
{
	int domain = AF_INET;//AF_INET
	int type = SOCK_STREAM;
	int protocol = 0;
	int ret  = -1;
	int nClientFd = -1;
	short int  port = 2000; 
	struct sockaddr_in addr_in;
	int len = 0;
	char chBuffer[1024] = {0};
	int flags = 0;
	char * pchServerIP = "192.168.1.211";
	
	nClientFd = socket( domain,  type,  protocol);
	if(nClientFd < 0)
	{
		printf("\n socket failed ! errno[%d]  err[%s]\n", errno, strerror(errno));
		return -1;
	}
 
    memset(&addr_in, 0, sizeof(struct sockaddr_in));
	addr_in.sin_family = AF_INET;
	addr_in.sin_port = htons(port);//htons的返回值是16位的网络字节序整型数   htons尾的字母s代表short
	//addr_in.sin_addr.s_addr = htonl(inet_addr(pchServerIP)); //错误的做法
	addr_in.sin_addr.s_addr = inet_addr(pchServerIP); 
	ret = connect(nClientFd, ( struct sockaddr * )(&addr_in), sizeof(struct sockaddr_in));
    if(ret < 0)
    {
    	printf("\n connect failed ! errno[%d]  err[%s]\n", errno, strerror(errno));
    	close(nClientFd); //避免资源泄漏
		return -1;
	}
 
	printf("\n  connect success ! \n");
	for(;;)
	{
		len = send(nClientFd, "2", sizeof("2"), flags); 
		sleep(2);
	}
	
	close(nClientFd);
 
	return 0;
}
 