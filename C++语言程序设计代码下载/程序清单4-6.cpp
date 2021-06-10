程序清单4-6
// ***************************************************************
// externDemo.cpp
// 演示extern的作用，说明变量引用性声明的概念
// ***************************************************************

#include <iostream>
using namespace std;

int main()
{
	extern int someInt;	// ①变量的引用性声明
	cout << "someInt=" << someInt << endl;
	return 0;
}
int someInt = 3;   	// ②变量的定义性声明
