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

struct student *getstu(struct student  *s)
{
     char name[20];
     printf("please input age:\n");
      
     scanf("%d",&(*s).age);
     printf("please input height:\n");  
     scanf("%d",&(*s).height);
     printf("please input sex:\n");
     scanf("%d",&(*s).sex);
     printf("please input name:\n");
     scanf("%s",name);
     strcpy(s->name,name) ;
     return(s);

}

void main()
{
   struct student s1,s2,s3;
   struct student *stu1,*stu2,*stu3;
   stu1=getstu(&s1);
   stu2=getstu(&s2);
   stu3=getstu(&s3);
   showstu(*stu1);
   showstu(*stu2);
   showstu(*stu3);
}
