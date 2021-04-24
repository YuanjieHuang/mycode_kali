#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
main()
{ 
   int fd,i;
   char path[]="/root/txt1.txt";
   extern int errno; 
   
   fd=open(path,O_WRONLY|O_CREAT);
   if(fd!=-1)
   {
      printf("opened file %s  .\n",path);
      printf("please input a number to lock the file.\n");
      scanf("%d",&i);
      if(flock(fd,LOCK_EX)==0)
      {
         printf("the file was locked.\n");	
	  }
	  else
	  {
	     printf("the file was not locked.\n");		
	  }
      printf("please input a number to unlock the file.\n");
      scanf("%d",&i);
      if(flock(fd,LOCK_UN)==0)
      {
         printf("the file was unlocked.\n");	
	  }
	  else
	  {
	     printf("the file was not unlocked.\n");		
	  }
      close(fd);	
   }
   else
   {
      printf("cant't open file %s.\n",path);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   }
} 
