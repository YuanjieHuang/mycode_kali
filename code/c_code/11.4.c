#include <stdio.h>
struct student
{
   char name[20];
   int age;
   int sex;
   int height;
}

main()
{
  struct student stu[50];
  int i=0;
  int j ;
  char s;
  char name[20];
  while(1)
  {
     printf("input a student?\n?Y/N:");
     scanf("%c",&s);
     if(s=='N'||s=='n')
     {
        break;
     }
     if(s!='n'&&s!='N'&&s!='y'&&s!='Y')
     {
        printf("error.\n");
        continue;
     }
     printf("please input age:\n");
     scanf("%d",&stu[i].age);
     printf("please input height:\n");
     scanf("%d",&stu[i].height);
     printf("please input sex:\n");
     scanf("%d",&stu[i].sex);
     printf("please input name:\n");
     scanf("%s",name);
     strcpy(stu[i].name,name) ;
     i++;
  }


  for(j=0;j<i;j++)
  {
    printf("Student[%d]\n",j);
    printf("  Name  :%s  \n",stu[j].name);
    printf("  Age   :%d  \n",stu[j].age);
    printf("  Sex   :%d  \n",stu[j].sex);
    printf("  Height:%d  \n",stu[j].height);

  }
}
