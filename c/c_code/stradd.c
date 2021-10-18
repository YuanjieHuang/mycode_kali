#include <stdio.h>

void stradd(char *a,char *b,char *c)
{
   while(*a!=NULL)
   {
       *c=*a;
       c++;
       a++;
   }
   while(*b!=NULL)
   {
       *c=*b;
       c++;
       b++;
   }
}

int main()
{
    char a[30]="abcdefg";
    char b[30]="HIJKLMN";
    char c[30]="";
    printf("a:  %s\n",a);
    printf("b:  %s\n",b);
    stradd(a,b,c);
    printf("c:  %s\n",c);
}

char *stradd1(char *a,char *b)                    /*定义一个连接字符串的函数,参数是3个指针。*/
{
   char *p;
   p=a;

   while(*a!=NULL)                                /*如果指针a对定的字符不是空字符则进行循环。*/
   {                                /*指针c向后移动一个元素。*/
       a++;                                    /*指针a指向下一个变量。*/
   }
   while(*b!=NULL)                                /*如果指针b指向的变量不为空字符则进行循环。*/
   {
       *a=*b;                                    /*指针b指向的字符赋值给指针c指向的字符。*/
        b++;                                   /*指针c指向下一个字符。*/
       a++;                                    /*指针b指向下一个字符。*/
   }
   return(p);
}

int stradd1_test()
{
    char a[30]="abcdefg";                            /*定义一个字符串数组，赋初值。*/
    char b[30]="HIJKLMN";                        /*定义一个字符串数组b，赋初值。*/
    char *c;                                /*定义一个字值串数组，赋值为空。*/
    printf("a:  %s\n",a);                            /*输出第1个字符串数组。*/
    printf("b:  %s\n",b);                            /*输出第2个字符串数组。*/
    c = stradd1(a,b);                                /*调用函数，连接两个字符串数组。*/
    printf("c:  %s\n",c);                           /*输出字符串c。*/

}

void order(int *x ,int *y,int *z);        /*声明一个函数。*/
void change(int *x,int *y);
void test_order()                                    /*主函数。*/
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
   if(*x > *y)
   {
     change(x,y);
   }
   if(*x > *z)
   {
       change(x,z);
   }
   if(*y > *z)
   {
      change(y,z);
   }

}

void change(int *x,int *y)
{
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
}