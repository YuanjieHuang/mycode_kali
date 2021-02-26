#include <stdio.h>
void change(int *x,int *y);           /*声明一个函数。*/

main()                                /*主函数。*/
{
   int m,n;                           /*定义两个变量。*/
   m=3;                               /*对两个变量赋值。*/
   n=5;
   printf("m:%d  n:%d\n",m,n);        /*输出两个变量。*/
   change(&m,&n);                     /*用函数交换两个变量。*/
   printf("m:%d  n:%d\n",m,n);        /*输出两个变量。*/
   change(&m,&n);                     /*用函数交换两个变量。*/
   printf("m:%d  n:%d\n",m,n);        /*输出两个变量。*/
}

void change(int *x,int *y)            /*定义一个函数，指针作为函数的参数。*/
{
   int temp;                          /*定义一个中间变量。*/
   temp=*x;                           /*指针指向的值赋值给中间变量。*/
   *x=*y;                             /*指针y指向的值赋值给指针x指向的值。*/
   *y=temp;                           /*中间变量的值赋值给指针y指向的值。*/
}

