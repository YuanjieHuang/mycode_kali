#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//int * p = NULL;
	//int **pp = NULL;
	//int ***ppp = NULL;


	//int ***************pppp = NULL;// 都是占用4个字节。
	//pp = &p;

	//char *p = "1234567"; //只读属性
	char *p = NULL;
	//char p_array[] = "1234567";
	//                ↑
	//*(p_array + 1) = 'x'; //*指针 在=左边的 一定保证 指针所指向的内存空间 可以被修改


	char ch; 


	ch = *p; //当*p 在=号右边的时候， 要保证 指针所指向的空间 可读

	printf("ch = %c\n", ch);

	//printf("%s\n", p_array);

	char buf[4] = { 0 };
	int i = 0;
	for (i = 0; i < 4; i++) {
		p = &buf[i];
	}


	int *p2 = NULL;
	int a = 10;

	p2 = &a;

	p2++; // p2 = (unsigned int)p2 + sizeof(int)

	char *p3 = NULL;

	strcpy(p3, "1234567");

	return 0;
}