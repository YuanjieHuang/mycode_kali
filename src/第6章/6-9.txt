//文件名：6-9.cpp
//全局变量的错误用法
#include <iostream>
using namespace std;
void f();

int main()
{   f();
    cout << "in main(): x= " << x << endl;
    return 0;
}

int x;

void f()
{
    cout << "in f(): x= " << x << endl;
}

