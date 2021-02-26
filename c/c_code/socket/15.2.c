#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>   

int  main(int argc,char *argv[])
{
   struct hostent *host;
   char addr[]="202.108.249.216";
   struct in_addr in;
   struct sockaddr_in addr_in;
   extern int h_errno;
   
   if((host=gethostbyaddr(addr,sizeof(addr),AF_INET))!=(struct hostent *)NULL)
   {
       memcpy(&addr_in.sin_addr.s_addr,host->h_addr,4);
       in.s_addr=addr_in.sin_addr.s_addr;
       printf("Domain name: %s \n",host->h_name);
       printf("IP length:    %d\n",host->h_length);
       printf("Type:    %d\n",host->h_addrtype);
       printf("IP          : %s \n",inet_ntoa(in));
    }
    else
    {  
   	    printf("error: %d\n",h_errno);
   		printf("%s\n",hstrerror(h_errno));
    } 
}
