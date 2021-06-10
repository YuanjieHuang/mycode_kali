程序清单1-1
// ***************************************************************
// prime.cpp
// 功能：判断用户从键盘输入的一个自然数是否为素数
// ***************************************************************

#include <iostream>	// 使用其中的cout和cin
#include <cmath>	// 使用其中的平方根函数sqrt

using namespace std;	// 使用名字空间std

bool primeNumber(unsigned);	// 函数原型

// 主函数
int main()
{
	unsigned value;	// value记录用户输入的自然数
	cout << "Enter a natural number:" << endl;
	cin >> value;

	if (primeNumber(value))
		cout << value << " is a prime number."<< endl;
	else
		cout << value << " is not a prime number."<< endl;

	return 0;
}

bool primeNumber(unsigned n)
// 判断n是否为素数
// 前置条件：
//     n已赋值
// 后置条件：
//     如果n是素数，则函数返回值为true;否则，函数返回值为false   
{
	unsigned divisor = 2;		// 除数
	unsigned remainder;		// 余数

	while (true) {
		// 求value除以divisor的余数
		remainder = n % divisor;	

		if (remainder == 0 && divisor != n) // n能被不等于n的divisor整除
			return false;

		divisor++;			// 除数加1
		if (divisor > sqrt(n))	// 除数大于n的平方根
			return true;
	}
}
