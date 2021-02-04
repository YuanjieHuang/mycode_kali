#include <stdio.h>
#include <errno.h>

main()
{
   FILE * fp;
   extern int errno; 
   char file[]="/root/a1.txt";
   fp=fopen(file,"r");
   if(fp==NULL)
   {
   	  printf("can't open file %s.\n",file);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   	  return;
   	}
   	else
   	{
   		printf("%s was opened.\n",file);   		
	}
   if(fclose(fp)==0)
   {
   	  printf("file was closed.\n");   	
   	}
   	else
   	{
   	  printf("can't close file .\n");
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));	
   	}   	 
}
