#include <stdio.h>
#include <stdlib.h>
struct student
{
   char name[20];
   int age;
   int sex;
   int height;
}


main()
{
   struct student stu;
   struct student *p;

   p=&stu;

   stu.age=15;
   strcpy(stu.name,"Jim");

   (*p).sex =1;
   (*p).height=168;

   printf("Name  : %s \n",stu.name);
   printf("Age   : %d \n",stu.age);
   printf("Sex   : %d \n",stu.sex);
   printf("Height: %d \n\n",stu.height);

   p->height=169;
   p->sex=0;

   printf("Name  : %s \n",stu.name);
   printf("Age   : %d \n",stu.age);
   printf("Sex   : %d \n",stu.sex);
   printf("Height: %d \n\n",stu.height);

   printf("Name  : %s \n",(*p).name);
   printf("Age   : %d \n",(*p).age);
   printf("Sex   : %d \n",p->sex);
   printf("Height: %d \n\n",p->height);
}
