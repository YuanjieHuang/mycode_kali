#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
main()
{ 
   int fd;
   char path[]="/root/a.txt";
   int size;
   char s[100];
   extern int errno; 
   
   fd=open(path,O_RDONLY);
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
   
   size=read(fd,s,sizeof(s));
   close(fd);
   printf("%s\n",s);
   printf("%d\n",size);
   close(fd);  
} 



