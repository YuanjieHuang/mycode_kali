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
   extern int errno; 
   
   fd=open(path,O_RDONLY ,0766);
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
   
   if(close(fd)==0)
   {
   	  printf("closed.\n");
   }
   else
   {
      printf("close file %s error.\n",path);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   }  
   
    if(close(1156)==0)
   {
   	  printf("closed.\n");
   }
   else
   {
      printf("close file %s error.\n",path);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   }
} 
