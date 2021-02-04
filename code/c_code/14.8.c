#include <stdio.h>
#include <errno.h>

main()
{
   FILE * fp;
   extern int errno; 
   char file[]="/root/a1.txt";
   fp=fopen(file,"r");
   int i;
   char a;
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
	for(i=0;i<10;i++)
	{
		a=getc(fp);
		if(a==EOF)
		{
			break;
		}
		printf("%c",a);
   }
   printf("\n");
   fclose(fp);   
}
