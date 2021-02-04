#include <stdio.h>
#include <errno.h>

void main()
{
   FILE * fp;
   extern int errno; 
   char file[]="/root/a1.txt";
   fp=fopen(file,"r");
   if(fp==NULL)
   {
   	  printf("cant't open file %s.\n",file);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   	  return;
   	}
   	else
   	{
   		printf("%s was opened.\n",file);   		
	}
   fclose(fp);
   
   fp=fopen("/root/a.sh","a");
   if(fp==NULL)
   {
   	  printf("cant't open file %s.\n",file);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   	}
   	else
   	{
   		printf("file was opened.\n");   		
	}
   fclose(fp);
   
    
   fp=fopen("/root/a.sh","a+");
   if(fp==NULL)
   {
   	  printf("cant't open file %s.\n",file);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   	  return;
   	}
   	else
   	{
   		printf("file was created.\n");   		
	}
   fclose(fp);
}
