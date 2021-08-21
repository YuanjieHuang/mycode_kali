//文件名：6-8.cpp
//静态局部变量的使用
#include<iostream>
using namespace std;

int f(int a);

int main()
{   int a=2,i;
    for (i=0; i<3; ++i)  cout << f(a);

    return 0;
}

int f(int a)
{   int b=0;
    static int c=3;

    b=b+1;   c=c+1;

    return(a+b+c);
}

