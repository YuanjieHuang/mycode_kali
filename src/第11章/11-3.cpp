　　//文件名：11-3.cpp
　　//重载了+和*运算符的Rational类
　　#include <iostream>
　　using namespace std;
　　
　　#include "Rational.h"
　　
　　int main()
　　{   Rational r1(1,6), r2(1,6), r3;
　　
　　    r3 = r1 + r2;  //r3 = r1.operator+(r2)
　　    r1.display(); cout << " + "; r2.display(); cout << " = "; r3.display(); cout << endl;
　　
　　    r3 = r1 * r2;  //r3 = r1.operator*(r2)
　　    r1.display(); cout << " * "; r2.display(); cout << " = "; r3.display(); cout << endl;
　　
　　    return 0;
　　}
　　
