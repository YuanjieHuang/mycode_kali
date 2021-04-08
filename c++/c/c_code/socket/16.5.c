#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#define LOCALPORT 4567

int   main(int argc,char *argv[])
{
    int mysock,len;
    struct sockaddr_in addr;
    int i=0;
    char msg[256];
    int addr_len;
      
    
    if (( mysock= socket(AF_INET, SOCK_DGRAM, 0) )<0)
    {
        perror("error");
        exit(1);
    }
    else
    {
    	printf("socket created .\n");
    	printf("socked id: %d \n",mysock);
	}
   
    addr_len=sizeof(struct sockaddr_in);
    bzero(&addr,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_port=htons(LOCALPORT);
    addr.sin_addr.s_addr=htonl(INADDR_ANY);
   
   
    if(bind(mysock,&addr,sizeof(addr))<0)
    {
        perror("connect");
        exit(1);
    }
    else
    {
    	printf("bind ok.\n");
    	printf("local port :%d \n",LOCALPORT);
    }
  
    while (1)
    {
    	bzero(msg,sizeof(msg));
        len= recvfrom (mysock,msg,sizeof(msg),0,&addr,&addr_len);/*接收到信息*/
        printf("%d :",i);
        i++;
        printf("message from : %s \n",inet_ntoa(addr.sin_addr));
        printf("  message length : %d \n",len);
        printf("  message : %s \n\n",msg);
        sendto(mysock,msg,len,0,&addr,addr_len); /*以上将字符串返回给客户端*/
    }  
}
