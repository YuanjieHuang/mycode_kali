　　//文件名：11-11.cpp
　　//Rational类的使用
　　#include <iostream.h>
　　#include "Rational.h"
　　
　　int main()
　　{   Rational r1, r2, r3;
　　    double x;
　　
　　    cout << "输入r1: ";  cin >> r1; //直接用cin输入有理数
　　    cout << "输入r2: ";  cin >> r2;
　　
　　    r3 = r1 + r2; //调用operator+实现加运算
　　    cout << r1 << '+' << r2 << " = " << r3 << endl; //直接用cout输出有理数
　　
　　    r3 = r1 * r2; //调用operator*实现乘运算
　　    cout << r1 << '*' << r2 << " = " << r3 << endl;
　　
　　    x = r3; //调用类型转换函数
　　    cout << "r3的double表示：" << x << endl;
　　
　　    return 0;
　　}
　　
