#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define PORT 6677
main()
{
   int sockfd,newsockfd,fd;
   struct sockaddr_in addr;
   int addr_len = sizeof(struct sockaddr_in);
   fd_set myreadfds;
   char msgbuffer[256];
   char msg[] ="This is the message from server.Connected.\n";
   
   if ((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)
   {
      perror("socket");
      exit(1);
   }
   else
   {
      printf("socket created .\n");
      printf("socked id: %d \n",sockfd);
   }
   
   bzero(&addr,sizeof(addr));
   addr.sin_family =AF_INET;
   addr.sin_port = htons(PORT);
   addr.sin_addr.s_addr = htonl(INADDR_ANY);
  
   if(bind(sockfd,&addr,sizeof(addr))<0)
   {
      perror("connect");
      exit(1);
   }
   else
   {
       printf("connected.\n");
       printf("local port:%d\n",PORT)	;
   }

   if(listen(sockfd,3)<0)
   {
      perror("listen");
      exit(1);
   }
   else
   {
      printf("listenning......\n");	
   }
 
   if((newsockfd = accept (sockfd,&addr,&addr_len))<0)
   {
      perror("accept");
   }
   else
   {
   	   printf("cnnect from %s\n",inet_ntoa(addr.sin_addr));
       if(read(newsockfd,msgbuffer,sizeof(msgbuffer))<=0)
       { 
         perror("accept");
       }
       else
       {    
          printf("message:\n%s \n",msgbuffer);
	    }
	 }
}

