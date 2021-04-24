#include <stdio.h>
#include <stdlib.h>

struct student
{
   char name[20];
   int age;
   int sex;
   int height;
}  ;

void showstu(struct student s)
{
   printf("A student:\n");
   printf("  Name  : %s \n",s.name);
   printf("  Age   : %d \n",s.age);
   printf("  Sex   : %d \n",s.sex);
   printf("  Height: %d \n\n",s.height);
}

struct student getstu(void)
{
     struct student stu;
     char name[20];
     printf("please input age:\n");   
     scanf("%d",&stu.age);
     printf("please input height:\n");  
     scanf("%d",&stu.height);
     printf("please input sex:\n");
     scanf("%d",&stu.sex);
     printf("please input name:\n");
     scanf("%s",name);
     strcpy(stu.name,name) ;
     return(stu);

}

void main()
{
   struct student stu1,stu2,stu3;
   stu1=getstu();
   stu2=getstu();
   stu3=getstu();
   showstu(stu1);
   showstu(stu2);
   showstu(stu3);
}
