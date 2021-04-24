#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
main()
{ 
   int fd;
   char path[]="/root/txt1.txt";
   char s[]="hello ,Linux.\nI've leart C program for two weeks.\n";
   extern int errno; 
   
   fd=open(path,O_WRONLY|O_CREAT);
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
   write(fd,s,sizeof(s));
   close(fd);  
   printf("Done");
} 
