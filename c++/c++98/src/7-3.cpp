//文件名：7-3.cpp
//返回引用值的函数示例
#include <iostream>
using namespace std;

int a[]={1,3,5,7,9};

int &index(int); //声明返回引用的函数

int main()
{   index(2)=25; //将a[2]重新赋值为25
    cout<<index(2);
    return 0;
}

int &index(int j)
{   return a[j]; }

