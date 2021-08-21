// *************************************************************
// lifetimeDemo.cpp
// 演示不同变量的生命期
// *************************************************************
#include <iostream>
using namespace std;
void test();
int  k = 0;		// k为全局变量
int main()
{
	test();
	test();
	test();
	return 0;
}
void test()
{
	int i = 0;			 // i为自动变量	
	static int j = 0;  // j为静态局部变量，注意其初始化在整个程序执行期间仅执行一次
	k++;
	i++;
	j++;
	cout << "i = "<< i << "  " << "j = " << j << "  " 
	      << "k = " << k << endl;
}
