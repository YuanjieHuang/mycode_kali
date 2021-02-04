#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
struct stu
{
	char name[10];
	int age;	
};
main()
{
   struct stu mystu[3];
   FILE * fp;
   extern int errno; 
   char file[]="/root/a1.txt";
   int i;
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
    close(fp);
}
