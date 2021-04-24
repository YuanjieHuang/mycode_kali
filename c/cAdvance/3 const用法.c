#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void const_test(const int *a/* 只读的 输入参数*/)
{
	*((int*)a) = 10;  //第一点const 在c语言中毫无地位， 第二天 C语言中强转可以任意转换
}

void const_test2(int *const a, int *buf)
{
	//a++; 
	*a = 20;
}

void const_test3(const int * const a)
{
	//a++;
	//*a = 20;
}

int main(void)
{
	int a = 10;
	const int b ; //具有了只读属性。

 //   int *p = &b;

	//*p = 30;

	//printf("%d\n ", b);

	//b = a;
	//a = b;  //const 一般 安全性较高的属性， 安全性较高的 付给一个 安全性低的。
	//b = a;

	return 0;
}