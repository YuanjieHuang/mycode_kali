#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void change_pointer(int **p)  //建立管理 int**p = &main::p;
{
	*p = (int*)0x00000000;
}

int main(void)
{
	int * p = NULL;

	change_pointer(&p);// change_pointer::p = &  main::p

	return 0;
}

#if 0
//123 写在一起
int main(void)
{
	int *p = NULL;

	//指针的直接赋值
	p = (int*)0x12345678;

	int **pp = NULL;   //条件一：  有两个变量 其中至少一个是指针

	//2 建立关联
	pp = &p;


	*pp = (int*)0x00000000;  //条件三 ： 间接操作

	return 0;
}
#endif