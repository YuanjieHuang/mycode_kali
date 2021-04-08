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
void main()
{
   struct student stu1,stu2;

   stu1.age=17;
   stu1.sex=1;
   stu1.height=176;
   strcpy(stu1.name,"Jim");
   stu2.age=23;
   stu2.sex=0;
   stu2.height=171;
   strcpy(stu2.name,"Lily");

   showstu(stu1);
   showstu(stu2);
}
