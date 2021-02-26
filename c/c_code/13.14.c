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
   struct flock fl;
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
   fl.l_type=F_RDLCK;
   fl.l_whence=SEEK_SET;
   fl.l_start=2;
   fl.l_len=10;
   fl.l_pid=15;
   if(fcntl(fd,F_SETLKW,&fl)==0)
   {
      printf("some string of the file was locked.\n");	
   }
   else
   {
   	  printf("locked error.\n");
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
    }
    close(fd);
} 
