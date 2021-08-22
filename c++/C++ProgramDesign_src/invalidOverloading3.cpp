// ***************************************************************
// invalidOverloading3.cpp
// 函数重载时容易出现的错误演示3
// ***************************************************************
#include <iostream>
#include <cmath> 					// fabs函数所在库
using namespace std;
// 函数名相同，但函数原型不同
bool equal(int, int);
bool equal(double, double);
int main()
{
	int    int1;
	double  double1;
	// 给变量赋值
	int1 = 3;
	double1 = 3.0000;
	// 输出两个数之间的关系
	switch(equal ((double)int1, double1)) { // 调用函数1
		case true: 
			cout << int1 << "==" << double1 << endl; 
			break;
		case false:	
			cout << int1 << "!=" << double1 << endl; 
			break;	
	}
	return 0;
}
// 函数1：比较两个整数是否相等，直接比较
bool equal(int num1, int num2)
{
    if(num1 == num2)
         return true;
    else
	    return false;
}
// 函数2：比较两个浮点数是否相等，采用近似比较的方法
bool equal(double num1, double num2)
{
	if(fabs(num1-num2) < 1e-6)
		return true;
	else
		return false;
}
