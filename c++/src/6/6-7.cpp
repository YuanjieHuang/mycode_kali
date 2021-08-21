//文件名：6-7.cpp
//函数模板的定义及使用
#include <iostream>

using namespace std;
template <class T>
T max(T a, T b)
{   return  a>b ? a : b; }

int main()
{   cout << "max(3,5) = " << max(3,5) <<endl;
    cout << "max(3.3, 2.5) = " << max(3.3, 2.5) <<endl;
    cout << "max('d', 'r') = " << max('d', 'r') <<endl;

    return 0;
}

