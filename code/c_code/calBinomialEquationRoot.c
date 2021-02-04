#include <stdio.h>
#include <math.h>
void main()
{
   float a ,b ,c ,s;
   float x1,x2;
   printf("please input a:\n");
   scanf("%f", &a);
   if(a==0)
   {
      printf("error.\n");
   }
   printf("please input b:\n");
   scanf("%f", &b);
   printf("please input c:\n");
   scanf("%f", &c);

   s=b*b - 4*a*c;
   if(s<0)
   {
       printf("no result.\n");
   }
   else
   {
      if(s==0)
      {
         printf("one result.\n");
         x1=(-b + sqrt(s))/(2*a);
         printf("reslut is x = %d\n",x1);
      }
      else
      {
         printf("two result.\n");
         x1=(-b+sqrt(s))/(2*a);
         x2=(-b-sqrt(s))/(2*a);
         printf("x1 = %f\n",x1);
         printf("x2 = %f\n",x2);
      }
   }
}
