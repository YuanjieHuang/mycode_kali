#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void main()
{  
	int fd;
    char path[]="./txt1.txt";
    FILE *fp;
    extern int errno; 
    
   fd=open(path,O_WRONLY|O_CREAT,0766);
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
   fp =fdopen(fd,"r");
}
