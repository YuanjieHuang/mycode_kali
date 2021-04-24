#include <stdio.h>
#include <errno.h>
#include <string.h>
/*
fputc/putc	fgetc getc
fputs/puts	fgets gets
fwrite		fread
fprintf		fscanf
frewind		fseek

*/
void main()
{
   FILE * fp;
   extern int errno; 
   char file[]="./a1.txt";
   char *txt="hello";
   int i;
   char ch[10];
   fp=fopen(file,"w+");
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
	fgets(ch,4,fp);
   	{
   		printf("%d char was written.\n",i);
		printf("%s\n",ch);
	}
	fclose(fp);
}
