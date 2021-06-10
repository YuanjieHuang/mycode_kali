//文件名：10-13.cpp
//IntArray类的使用
#include <iostream>
using namespace std;
#include "IntArray.h"

int main()
{   IntArray array(20,30);
    int value, i;

    for (i=20; i<=30; ++i) {
         cout<< "请输入第" << i << "个元素:";  cin >> value;
         array.insert(i, value);
    }

    while (true) {
        cout << "请输入要查找的元素序号（0表示结束）:";
        cin >> i;
        if (i == 0) break;
        if (array.fatch(i, value)) cout << value << endl;
            else cout << "下标越界\n";
    }
    return 0;
}
　　
