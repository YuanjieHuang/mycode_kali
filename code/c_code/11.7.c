#include <stdio.h>

struct student
{
   char name[20];
   int age;
   int sex;
   int height;
}  ;

void showstu(struct student *p)
{
   printf("A student:\n");
   printf("  Name  : %s \n",p->name);
   printf("  Age   : %d \n",p->age);
   printf("  Sex   : %d \n",p->sex);
   printf("  Height: %d \n\n",p->height);
}

void main()
{
   struct student stu1,stu2;
   struct student *p1,*p2;

   p1=&stu1;
   p2=&stu2;
   stu1.age=17;
   stu1.sex=1;
   stu1.height=176;
   strcpy(stu1.name,"Jim");
   stu2.age=23;
   stu2.sex=0;
   stu2.height=171;
   strcpy(stu2.name,"Lily");

   showstu(p1);
   showstu(p2);
}
