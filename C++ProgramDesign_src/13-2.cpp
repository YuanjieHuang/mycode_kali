// ***************************************************************
// functMatching.cpp
// 功能： 演示重载函数的静态绑定
// ***************************************************************
#include <iostream>
#include <string>
using namespace std;
// 定义函数模板demoFunc
template <typename T>
void demoFunc(const T v1, const T v2)
// 输出版本提示及形参v1、v2的值
// 前置条件： v1和v2已赋值
// 后置条件：
//     在标准输出设备上输出，字符串"the first generic version of demoFunc()"以及v1、v2的值
{	
	cout << "the first generic version of demoFunc()" << endl;
	cout << "the arguments: " << v1 << " " << v2 << endl;
}
// 定义函数模板demoFunc的重载版本
template <typename T>
void demoFunc(const T v)
// 输出版本提示及形参v的值
// 前置条件： v已赋值
// 后置条件：
//     在标准输出设备上输出，字符串"the second generic version of demoFunc()"以及v的值
{	
	cout << "the second generic version of demoFunc()" << endl;
	cout << "the argument: " << v << endl;
}
// 定义重载函数模板demoFunc的非模板函数
void demoFunc(const int v1, const int v2)
// 输出版本提示及形参v1、v2的值
// 前置条件： v1和v2已赋值
// 后置条件：
//     在标准输出设备上输出，字符串"the ordinary version of demoFunc()"以及v1、v2的值
{	
	cout << "the ordinary version of demoFunc()" << endl;
	cout << "the arguments: " << v1 << " " << v2 << endl;
}
int main()
{
	char ch1 = 'A', ch2 = 'B';
	int iv1 = 3, iv2 = 5;
	double dv1 = 2.8, dv2 = 8.5;
	// 调用第一个函数模板的实例demoFunc(double, double)
	demoFunc(dv1, dv2);	
	demoFunc(iv1);		// 调用第二个函数模板的实例demoFunc(int)
	demoFunc(iv1, iv2);  	// 调用非模板函数demoFunc(int, int)
	// 调用非模板函数demoFunc(int, int)(进行隐式类型转换)
	demoFunc(ch1, iv2);	
	return 0;
} 
