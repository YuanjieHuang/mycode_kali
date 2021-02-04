#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
main()
{ 
   extern int errno;
   char path[]="mytemp";
   
   if(remove(path)==0)
   {
      printf("Deleted file %s.\n",path);	
   }
   else
   {
      printf("cant't delete the file %s.\n",path);
   	  printf("errno: %d\n",errno);
   	  printf("ERR  : %s\n",strerror(errno));
   }
} 
