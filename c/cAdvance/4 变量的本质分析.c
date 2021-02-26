#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

//
//int g_a = 100;

int main(void)
{
	int a = 10; 


	int *p = &a;

	*p = 20;	
	//通过间接修改 a内存块的值

	int addr = 0;

	addr = (int)&a;

	*((int*)addr) = 200;

	printf("a = %d\n", a);

	//a 的地址 是 7339396 

	*((int*)(73339396)) = 400; //间接的修改了a的变量

	printf("&a = %d\n", &a);
	


	return 0;
}