#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
int  main()
{
  int s;
   if((s = socket(AF_INET,SOCK_STREAM,0))<0)
  {
    perror("connect");
    exit(1);
  }
  else
  {
  	  printf("a socket was created.\n");
  	  printf("socket number:%d\n",s);
   }
   
  if((s = socket(AF_INET,123,0))<0)
  {
    perror("connect");
    exit(1);
  }
  else
  {
  	  printf("a socket was created.\n");
  	  printf("socket number:%d\n",s);
  	}
}
