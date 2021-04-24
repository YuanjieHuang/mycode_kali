#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
/*
fputc/putc	fgetc getc
fputs/puts	fgets gets
fwrite		fread
fprintf		fscanf
frewind		fseek

*/
struct stu
{
	char name[10];
	int age;	
};
void main()
{
   struct stu mystu[3];
   FILE * fp;
   extern int errno; 
   char file[]="./a1.txt";
   int i;
   char str[100];
   strcpy(mystu[0].name,"Jim");
   mystu[0].age=14;
   strcpy(mystu[0].name,"Jam");
   mystu[1].age=14;  
   strcpy(mystu[0].name,"Lily");
   mystu[2].age=19; 
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
 
    i=fwrite(mystu,sizeof(mystu),3,fp);
    printf("%d students was written.\n",i);
    fread(str,sizeof(mystu),3,fp);
    printf("%s.\n",str);
    fclose(fp);
}
