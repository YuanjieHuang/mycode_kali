//文件名：6-6.cpp
//重载函数示例
#include <iostream>
using namespace std;

int max(int a1, int a2);
int max(int a1, int a2, int a3);
int max(int a1, int a2, int a3, int a4);
int max(int a1, int a2, int a3, int a4, int a5);

int main()
{   cout << "max(3,5) is " << max( 3,5) << endl;
    cout << "max(3,5,4) is " << max( 3,5,4) << endl;
    cout << "max(3,5,7,9) is " << max( 3,5,7,9) << endl;
    cout << "max(3,5,2,4,6) is " << max( 3,5,2,4,6) << endl;

    return 0;
}

int max(int a1, int a2) {return a1>a2 ? a1 : a2;}

int max(int a1, int a2, int a3)
{   int tmp;   
    if (a1 > a2) tmp = a1; else tmp = a2;
    if (a3 > tmp) tmp = a3;  

    return tmp;
}

int max(int a1, int a2, int a3, int a4)
{   int tmp;   

    if (a1 > a2) tmp = a1; else tmp = a2;
    if (a3 > tmp) tmp = a3;
    if (a4 > tmp) tmp = a4;

    return tmp;
}

int max(int a1, int a2, int a3, int a4, int a5)
{   int tmp;   
    if (a1 > a2) tmp = a1; else tmp = a2;
    if (a3 > tmp) tmp = a3;
    if (a4 > tmp) tmp = a4;
    if (a5 > tmp) tmp = a5;

    return tmp;
}

