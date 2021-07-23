//文件名：5-1.cpp
//数组输入/输出示例
#include <iostream>
using namespace std;

int main()
{   int a[10], i;

    cout << "请输入10个整型数：\n";
    for (i=0; i<10; ++i)  cin >> a[i];

    cout << "\n数组的内容为：\n";
    for (i=0; i< 10; ++i)   cout << a[i] << '\t';

    return 0;
}

