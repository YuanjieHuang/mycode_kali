#include<ctype.h>
#include<stdio.h>
void main()
{
   char s[100];
   int i,c_num,c_lower,c_upper,c_mark ;
   c_num=0;
   c_lower=0;
   c_upper=0;
   c_mark=0;
   printf("please input a string:\n");
   scanf("%s",s);
   for(i=0;s[i]!='\0' && i < 100;i++)
   {
      if(isdigit(s[i]))
      {
         c_num++;
      }
      if(islower(s[i]))
      {
         c_lower++;
      }
      if(isupper(s[i]))
      {
         c_upper++;
      }
      if(ispunct(s[i]))
      {
         c_mark++;
      }
   }
   printf("upper: %d\n",c_upper);
   printf("lower: %d\n",c_lower);
   printf("mark: %d\n",c_mark);
   printf("number: %d\n",c_num);
   printf("total: %d\n",i);
}
