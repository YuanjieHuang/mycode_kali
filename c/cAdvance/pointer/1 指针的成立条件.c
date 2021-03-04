#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int change_value(int *p)
{
	*p = 30; //  条件三 ：  在函数的内部改变 变量
}

//条件1 2 写在一起， 条件三 写在另一个函数中
//条件1 写在一个函数中 ，23 写在一起。 //引用
int main(void)
{
	int  a = 10;  

	change_value(&a); // int *p = &a; //  条件一 和 条件二 在一个函数中， main函数中


	return 0;
}

/*
//条件123 写在一个函数中
int main(void)
{
	int a = 10; //一个变量

	int *p = NULL; //又一个变量     条件一:要有两个变量，（至少其中一个是指针类型）

	p = &a; // 条件二：  建立关联  

	*p = 30; //条件三 ：通过指针 间接的操作变量

	return 0;
}
*/