#include <stdio.h>
#include <stdlib.h>
struct student
{
   char name[20];
   int age;
   int sex;
   int height;
}  ;

void delestu();
int menu();
struct student getstu(void);
void selectbyname();
void selectbyage();
void selectbysex();
void selectbyheight();
void showstu(struct student s);



int i;
struct student stu[100];

void showstu(struct student s)
{
   printf("A student:\n");
   printf("  Name  : %s \n",s.name);
   printf("  Age   : %d \n",s.age);
   printf("  Sex   : %d \n",s.sex);
   printf("  Height: %d \n\n",s.height);
}

int menu()
{
   int i;
   i=0;
   while(1)
   {
      printf("Please select a menu:\n");
      printf("       1: add a student.\n");
      printf("       2: list the name all the student.\n");
      printf("       3: list informations of all the student.\n");
      printf("       4: select a student by name .\n");
      printf("       5: select students  by age .\n");
      printf("       6: select students  by sex .\n");
      printf("       7: select students  by height .\n");
      printf("       8: delete a student .\n");
      printf("       9: exit .\n");
      scanf("%d",&i);
      if(i==9)
      {
         printf("Byebye.\n");
         exit(1);
      }
      if(i<1 || i>9)
      {
         printf("error.\n");
         continue;
      }
      else
      {
         return(i);
      }
   }
}

struct student getstu(void)
{
     struct student stu;
     char name[20];
     printf("Add a student:\n"); 
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

void selectbyname()
{  
   int j,n;
   char name[20];
   n=0;
   printf("please input a name;\n");
   scanf("%s",name);
   for(j=0;j<i;j++)
   {
     if(strcmp(stu[j].name,name))
     {
        showstu(stu[j]);
        n++;
     }
   }
   if(n==0)
   {
      printf("there is no such a student.\n");
   }
}

void delestu()
{  
   int j,n;
   char name[20];
   n=0;
   printf("delete a student:\n");
   printf("please input a name:\n");
   scanf("%s",name);
   for(j=0;j<i;j++)
   {
     if(strcmp(stu[j].name,name))
     {   
         for( ;j<i-1;j++)
         {
            stu[j]=stu[j+1];
         }
         i--;
         break;
     }
     
   }
       
   if(n==0)
   {
      printf("there is no such a student.\n");
   }
}

void selectbyage()
{  
   int j,k,t,n;
   n=0;
   printf("please input a top age:\n");
   scanf("%d",&j);
   printf("please input a bottom age:\n");
   scanf("%d",&k);
   for(t=0;t<i;t++)
   {
     if(stu[t].age<=j &&stu[t].age>k)
     {
        showstu(stu[t]);
        n++;
     }
   }
   if(n==0)
   {
      printf("there is no such a student.\n");
   }
}
void selectbyheight()
{  
   int j,k,t,n;
   n=0;
   printf("please input a top height:\n");
   scanf("%d",&j);
   printf("please input a bottom  height:\n");
   scanf("%d",&k);
   for(t=0;t<i;t++)
   {
     if(stu[t].height<=j &&stu[t].height>k)
     {
        showstu(stu[t]);
        n++;
     }
   }
   if(n==0)
   {
      printf("there is no such a student.\n");
   }
}

void selectbysex()
{  
   int j,t,n;
   n=0;
   printf("please input the sex:\n");
   scanf("%d",&j);
   for(t=0;t<i;t++)
   {
     if(stu[t].sex==j)
     {
        showstu(stu[t]);
        n++;
     }
   }
   if(n==0)
   {
      printf("there is no such a student.\n");
   }
}

int  main()
{
   int s,j;
   i=0;
   while(1)
   {
      s=menu();
      if(s==1)
      {
         stu[i]=getstu();
         i++;
      }
      if(s==2)
      {
         printf("All the students:\n");
         for(j=0;j<i;j++)
            {
               printf("  %d:  %s\n",j,stu[j].name);
            }
      }
      if(s==3)
      {
         for(j=0;j<i;j++)
         {

            showstu(stu[j]);
         }
      }
      if(s==4)
      {
         selectbyname();
      }
      if(s==5)
      {
         selectbyage();
      }
      if(s==6)
      {
         selectbysex();
      }
      if(s==7)
      {
         selectbyheight();
      }
      if(s==8)
      {
         delestu();
      }
   }
}
