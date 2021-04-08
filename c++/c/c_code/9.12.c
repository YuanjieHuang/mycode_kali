#include <stdio.h>
/*声明一个函数。*/
void order(int *x ,int *y,int *z);
main()                                 /*主函数。*/
{
   int a,b,c;
   a=5;
   b=3;
   c=8;
   printf("%d %d %d\n",a,b,c);
   order(&a,&b,&c);
   printf("%d %d %d\n",a,b,c);
}


void order(int *x ,int *y,int *z)
{
   int temp;
   if(*x > *y)
   {
      temp=*x;
      *x=*y;
      *y=temp;
   }
   if(*x > *z)
   {
      temp=*x;
      *x=*z;
      *z=temp;
   }
   if(*y > *z)
   {
      temp=*y;
      *y=*z;
      *z=temp;
   }

}
