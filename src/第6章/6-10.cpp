//file1.cpp

#include <iostream>
using namespace std;

void f();
extern x; 	//外部变量的声明

int main()
{   f();
    cout << "in main(): x= " << x << endl;
    return 0;
}

//file2.cpp

#include <iostream>
using namespace std;

int x; 	//全局变量的定义

void f()
{ 
    cout << "in f(): x= " << x << endl; 
}

