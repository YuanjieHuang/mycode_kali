#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <errno.h>
main()
{ 
   extern int errno;
   char *path="/root/tmp11";
   
   if(mkdir(path,0766)==0)
   {
   	  printf("created the directory %s.\n",path);
   }
   else
   {   	  
   	  printf("cant't creat the directory %s.\n",path);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));	
   }
} 

 

