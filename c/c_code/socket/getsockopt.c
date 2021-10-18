#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
int  main()
{
  int s;
  int val,len ;
  len= sizeof(int);
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
   getsockopt(s,SOL_SOCKET,SO_TYPE,&val,&len);
   perror("socket:");
   printf("optval = %d\n",val);
    getsockopt(100,SOL_SOCKET,SO_TYPE,&val,&len);
   perror("socket:");
}
