//文件名：7-1.cpp
//数组作为函数的参数的示例
#include <iostream>
using namespace std;

void f(int arr[]);

int main()
{   int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    cout << sizeof(array) << endl;
    f(array);

    return 0;
}

void f(int arr[])
{    cout << sizeof(arr) << endl; }

