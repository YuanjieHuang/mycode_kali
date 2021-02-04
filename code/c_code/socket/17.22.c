#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#define PORT 80
#define REMOTE_IP "202.108.249.216"

int   main(int argc,char *argv[])
{   
   int s ;
   struct sockaddr_in addr ;
   char mybuffer[256];

   if( (s=socket(AF_INET,SOCK_STREAM,0))<0 )
   {
      perror("socket");
      exit(1);
   }
   else
   {
    	printf("socket created .\n");
    	printf("socked id: %d \n",s);
	}

   bzero(&addr,sizeof(addr));
   addr.sin_family =AF_INET;
   addr.sin_port=htons(PORT);
   addr.sin_addr.s_addr=inet_addr(REMOTE_IP);

   if(connect(s,&addr,sizeof(addr))<0)
   {
      perror("connect");
      exit(1);
   }
   else
   {
   	   printf("connected ok!\n");
   	   printf("remote ip:%s\n",REMOTE_IP);
   	   printf("remote port:%d\n",PORT);
    }
}
