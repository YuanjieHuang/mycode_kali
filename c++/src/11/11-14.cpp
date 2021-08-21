　　//文件名：11-14.cpp
　　//IntArray类的使用
　　#include "IntArray.h"
　　
　　int main()
　　{   IntArray array1(20,30), array2;
　　
　　    cin >> array1; //利用流提取运算符重载输入array1
　　    cout << "array1 "; cout << array1; //利用流插入运算符重载输出array1
　　
　　    array2 = array1; //利用赋值运算符重载将array1赋给array2
　　
　　    cout << "执行 array2 = array1, array2 ";
　　    cout << array2;
　　
　　    //利用==重载比较array1和array2
　　    cout << "array1 == array2 是 " << ((array1 == array2)  ? "true" : "false") << endl; 
　　
　　    array2[25] = 0; //利用下标运算符重载为array2的元素赋值
　　
　　    cout << "执行array[25] = 0后, array1 == array2 是 "
　　         << ((array1 == array2)  ? "true" : "false") << endl; 
　　
　　    return 0;
　　}
　　
