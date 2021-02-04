#include <stdio.h>
#include <errno.h>

main()
{
   FILE * fp;
   extern int errno; 
   char file[]="/root/a1.txt";
   char txt[5]="hello";
   int i=0;
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
	
   
   for(i=0;i<5;i++)
   {
   	  putc(txt[i],fp);
   	  printf("%c",txt[i]);

   	}   	
   	fclose(fp);    
}
