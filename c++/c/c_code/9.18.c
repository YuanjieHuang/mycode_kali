#include <stdio.h>
void  add(int a,int b,int *c)                    /*定义一个连接字符串的函数,参数是3个指针。*/
{
   *c=a+b;
}

int main()
{
    int a,b,c;
    a=5;
    b=8;
    add(a,b,&c);
    printf("reslut is %d",c);
}
