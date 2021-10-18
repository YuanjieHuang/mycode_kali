#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <errno.h>
#include <fcntl.h>
void mkdir_tmp()
{ 
   extern int errno;
   char *path="./tmp";
   
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


 
void rmdir_test()
{ 
   extern int errno;
   char *path="/root/tmp11";
   
   if(rmdir(path)==0)
   {
   	  printf("deleted the directory %s.\n",path);
   }
   else
   {   	  
   	  printf("cant't delete the directory %s.\n",path);
   	  printf("errno : %d\n",errno);
   	  printf("ERR  : %s\n",strerror(errno));	
   }
}

void creat_()
{ 
   extern int errno;
   char *path="/root/tmp.txt";
   
   if(creat(path,0766)==-1)
   {
  	   printf("cant't create the file %s.\n",path);
      printf("errno：%d\n",errno);
      printf("ERR  ：%s\n",strerror(errno));
   }
   else
   {   	  
      printf("created file %s.\n",path);	
   }
} 

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