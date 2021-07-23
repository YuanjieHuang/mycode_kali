//文件名：5-3.cpp
//顺序查找
#include <iostream>
using namespace std;

int main()
{   int  k, x;
    int array[ ] = { 2, 3, 1, 7, 5, 8, 9, 0, 4, 6};

    cout << "请输入要查找的数据：";
    cin >> x;

    for (k = 0; k < 10; ++k)
        if (x == array[k])  { cout << x << "的存储位置为：" << k; break;}
    if (k == 10) cout << "没有找到";

    return 0;
}

