#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
main()
{ 
   int fd,fd2,size,i=1;
   char path[]="/root/s.txt";
   char newpath[]="/root/a2.txt";
   char buf[100];
   struct flock fl;
   extern int errno; 
   
   fd=open(path,O_RDONLY);
   fd2=open(newpath,O_WRONLY|O_CREAT);
   if(fd!=-1)
   {
      printf("opened file %s  .\n",path);	
   }
   else
   {
      printf("cant't open file %s.\n",path);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   }
   for(;i!=0;)
   { 
   		
   	   i=read(fd,buf,sizeof(buf));
   	   if(i==-1)
   	   {
   	      break; 
	   }
	   else
	   {
   	      write(fd2,buf,sizeof(buf));
       }
   }
   printf("file was copied.\n");
   close(fd);
   close(fd2);
} 
