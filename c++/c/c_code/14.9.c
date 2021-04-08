#include <stdio.h>
#include <errno.h>
#include <string.h>

void main()
{
   FILE * fp;
   extern int errno; 
   // char file[]="/root/a1.txt";
   char file[]="./a1.txt";
   fp=fopen(file,"w");
   int i;
   char a[5]="abcd";
   char b[5];
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
   fgets(b,5,fp);
   fputs(a,fp);
   printf("%s\n",b);
   fclose(fp); 
   fp =fdopen(fd,"r");  
}
