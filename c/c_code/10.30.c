#include<ctype.h>
#include<stdio.h>
int istel(char *p)
{
   int i ;
   i=0 ;

   while(*p!='\0')
   {
     if(!isdigit(*p))
     {
        return 0;
     }
     i++;
     if(i>13)
     {
        return 0;
     }
     p++;
   }
   if(i<3)
   {
      return 0;
   }
   return 1;
}
int isname(char *p)
{
   int i ;
   i=0 ;

   while(*p!='\0')
   {
     if(!isalpha(*p))
     {
        return 0;
     }
     i++;
     if(i>20)
     {
        return 0;
     }
     p++;
   }
   if(i<3)
   {
      return 0;
   }
   return 1;
}

void main()
{
   char name[50];
   char tel[50];
   char *q;

   printf("please input a telephone number:\n");
   scanf("%s",tel);
   q=tel;
   if(istel(q))
   {
      printf("%s is a telephoe number.\n ",tel);
   }
   else
   {
      printf("%s is not  a telephoe number.\n ",tel);
   }

   printf("please input a name:\n");
   scanf("%s",name);
   q=name;
   if(isname(q))
   {
      printf("%s is a name.\n ",name);
   }
   else
   {
      printf("%s is not  a name.\n ",name);
   }
}


