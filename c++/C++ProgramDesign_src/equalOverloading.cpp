// ***************************************************************
// equalOverloading.cpp
// 判断是否相等的函数重载
// ***************************************************************
#include <iostream>
#include <cmath> 		// fabs函数所在库
#include <cstring> 		
using namespace std;
// 函数重载，函数名相同，但函数原型不同
bool equal(int, int);
bool equal(float, float);
bool equal(char * , char * );
int main()
{
	int    int1, int2;
	float  float1, float2;
	char * str1, * str2;
	// 给变量赋值
	int1 = 3;
	int2 = 6;
	float1 = 3.33333;
	float2 = 3.33332;
	// 申请空间存放字符串
  	str1 = new char[40];
	str2 = new char[40];
	strcpy(str1, "Hello");
	strcpy(str2, "hello");
	// 输出两个整数之间的关系
	switch(equal (int1, int2)) { 		// 调用函数1
		case true: 	
			cout << int1 << "==" << int2 <<endl;
			break;
		case false:	
			cout << int1 << "!=" << int2 <<endl; 
			break;	
	}
	//输出两个浮点数之间的关系
	switch(equal (float1, float2)) { 	// 调用函数2
		case true: 
			cout << float1 << "==" << float2 <<endl;
			break;
		case false:	
			cout << float1 << "!=" << float2 <<endl; 
			break;	
	}
	// 输出两个字符串之间的关系
	switch(equal (str1, str2)) { 		// 调用函数3　	
		case true: 
			cout << str1 << "==" << str2 <<endl;
			break;
		case false:
			cout << str1 << "!=" << str2 <<endl; 
			break;	
	}
	// 释放存放字符串的空间
	delete [] str1;
	delete [] str2;
	return 0;
}
bool equal ( int num1, int num2 ) 
// 比较两个整数是否相等，直接比较
// 前置条件：num1, num2已经赋值
// 后置条件：如果num1, num2相等则返回为true, 否则返回false
{
    if(num1==num2)
        return true;
    else
		return false;
};
bool equal ( float num1, float num2 )
// 比较两个整数是否相等，采用近似比较的方法
// 前置条件：num1, num2已经赋值
// 后置条件：如果num1, num2相等则返回为true, 否则返回false
{
    if ( fabs ( num1 - num2 ) < 1e-6 )
        return true;
    else
        return false;
}
bool equal(char * str1, char * str2)
// 比较两个字符串是否相等，调用库函数实现
// 前置条件：str1, str2已经赋值
// 后置条件：如果str1, str2相等则返回为true, 否则返回false
{
    if ( strcmp ( str1, str2 ) == 0 )
        return true;
    else
        return false;
}
