#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>


//栈
void test()
{
	int a = 10; //局部变量 在栈上开辟内存  是由操作系统自动在栈上开辟的
	int b = 20;
	int array[10]; 

	{
		int c;
		int d;

	}

}

//全局区包括 静态区（全局变量和 静态的局部或者全部变量） 和常量区
int g_a; 


//堆
void test2()
{
	char * p = NULL; // 在栈上开辟4个字节。
	char *str = "1234567";


	//在堆上开辟空间
	p = (char*)malloc(100);
	if (p == NULL) {
		fprintf(stderr, "malloc error\n");
		return;
	}
	static int b = 20;

	//释放堆的空间
	if (p != NULL) {
		free(p);
		p = NULL;
	}

}

int main(void)
{

	return 0;
}