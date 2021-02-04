#include <stdio.h>
#include <errno.h>

main()
{
   FILE * fp;
   extern int errno; 
   char file[]="/root/a1.txt";
   fp=fopen(file,"r");
   int i;
   char a[5];
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
    fgets(a,5,fp);
   printf("%s\n",a);
   fclose(fp);   
}
