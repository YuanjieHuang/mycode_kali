#include <stdio.h>
#include <errno.h>

main()
{ 
   char path[]="/root/a.txt";
   char path1[]="/root/a11.txt";
   char newpath[]="/tmp/b.txt";
   extern int errno;
   if(rename(path,newpath)==0)
   {
      printf("the file %s was moved to %s .\n",path,newpath);	
   }
   else
   {
      printf("can't move the file %s .\n",path);	
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   }
  
   if(rename(path1,newpath)==0)
   {
      printf("the file %s was moved to %s .\n",path1,newpath);	
   }
   else
   {
      printf("can't move the file %s .\n",path1);	
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   }
} 
