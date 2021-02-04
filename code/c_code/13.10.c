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
   int size;
   char s[100]="";
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
   
   size=read(fd,s,3);    
   printf("%d  :",size);
   printf("%s\n",s);
  
   size=read(fd,s,3); 
   printf("%d  :",size);
   printf("%s\n",s);
   
   lseek(fd,8,SEEK_SET);
   size=read(fd,s,3);
   printf("%d  :",size);
   printf("%s\n",s);

   lseek(fd,0,SEEK_SET);
   size=read(fd,s,3);
   printf("%d  :",size);
   printf("%s\n",s);
         
   close(fd);  
} 

