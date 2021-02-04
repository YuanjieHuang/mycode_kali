#include <stdio.h>
#include <errno.h>

main()
{
   FILE * fp;
   extern int errno; 
   char file[]="/root/a1.txt";
   char *txt="hello";
   int i;
   fp=fopen(file,"a+");
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
 
   	i=fputs(txt,fp);
   	{
   		printf("%d char was written.\n",i);
	}
	close(fp);
}
