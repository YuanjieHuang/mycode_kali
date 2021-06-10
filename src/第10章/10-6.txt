//文件名：10-6.cpp
//改进后的array库的应用示例
#include <iostream>
using namespace std;
#include "new-array.h"

int main()
{   IntArray array;
    int value, i;

    if (!array.initialize(20, 30)) { cout << "空间分配失败" ; return 1;}
    //数组array的初始化

    for (i=20; i<=30; ++i) { //数组元素的输入
         cout << "请输入第" << i << "个元素:";
         cin >> value;
         array.insert(i, value);
    }

    while (true) { //数组元素的查找
        cout << "请输入要查找的元素序号(0表示结束）:";
        cin >> i;
        if (i == 0) break;
        if (array.fatch(i, value)) cout << value << endl;
            else cout << "下标越界\n";
    }

    array.cleanup();  //归还存储数组元素的空间

    return 0;
}

