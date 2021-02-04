#include <stdio.h>
#include <errno.h>

main()
{
  FILE *fp;
  char path[]="/root/txt1.txt";
  extern int errno; 
  fp=freopen("/root/txt1.txt","r",fp);
  if(fp==NULL)
  {
   	  printf("cant't open file %s.\n",path);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   	  return;
   }
   else
   {
   	  printf("%s was opened.\n",path);   		
   	}	
}
