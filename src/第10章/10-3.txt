//文件名：10-3.cpp
//array库的应用示例
#include <iostream>
using namespace std;
#include "array.h" 

int main() 
{   IntArray array; 					//IntArray是array库中定义的结构体类型
    int value, i;

    //初始化数组array，下标范围为20到30
    if (!initialize(array, 20, 30)) { cout << "空间分配失败" ; return 1;}

    for (i=20; i<=30; ++i) { 			//数组元素的输入
         cout << "请输入第" << i << "个元素：";
         cin >> value;
         insert(array, i, value); 		//将value存入数组array的第i个元素
    }

    while (true) { 					//数组元素的引用
           cout << "请输入要查找的元素序号（0表示结束）：";
           cin >> i;
           if (i == 0) break;
           if (fatch(array, i, value)) cout << value << endl;
               else cout << "下标越界\n";
    }

    cleanup(array);					//回收array的空间

    return 0;
}

