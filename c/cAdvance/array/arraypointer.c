#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void test()
{
	//int//0维数组  一级指针
	//int[10]//一维数组， 二级指针
	//int[10][20]//二维数组， 三级指针
	int a[3][4];
	//  a 是一个 指针，  指向  此二维数组首元素（int[4]）的地址， int (*)[4]   ==>二级指针 指向一维数组
	// &a 也是一个指针， 指向 此二维数组(int[3][4])的地址,   int(*p)[3][4]  ---> 三级指针  指向一个二维数组
	//一个数组指针， 如果是几级指针， 就是 指向比他低一个维度的数组。
}
int main(void)
{
	//定义一个指针数组
	//char *pointer_array[4] = { NULL, NULL, NULL, NULL };//在栈上
	char *pointer_array[4] = { 0}; 
	int i = 0;
	for (i = 0; i < 4; i++) {
		pointer_array[i] = malloc(100);
	}
	//定义一个数组指针
	//方法一
	//直接定义一个数组类型
	typedef int(ARRAY_CHAR_4)[4];  
	ARRAY_CHAR_4 array = { 0 };  //(int[4]) array 是数组首元素的地址  
	ARRAY_CHAR_4 *p = NULL;   //数组的地址   (int[4]) * p = NULL;
	p = &array;  //  array  int*   &array --> (int[4])*
	for (i = 0; i < 4; i++) {
		(*p)[i] = i;  // array[i] = i;
		// char[4]    *(p +  i) === p[i]
	}
	for (i = 0; i < 4; i++) {
		printf("%d\n", array[i]);
	}
	int size = 0;
	size = sizeof(ARRAY_CHAR_4);
	printf("ARRAY_CHAR_4 = %d\n ", size);  // 16
	/*
	int *p = NULL;
	typedef int* POINT;
	POINT p;
	*/
	//方法二
	typedef int(*ARRAY_CHAR_4_POINTER)[4];  //p  ----> int[10]
	typedef int(*ARRAY_CHAR_10_POINTER)[10]; //int[10]
	ARRAY_CHAR_4_POINTER  array_pointer = &array;
	size = sizeof(ARRAY_CHAR_4_POINTER);
	printf("ARRAY_CHAR_4_POINTER = %d\n ", size); //4
	for (i = 0; i < 4; i++) {
		(*array_pointer)[i] = 10 - i;
	}
	printf("\n");
	for (i = 0; i < 4; i++) {
		printf("%d\n", array[i]);
	}
	//方法三
	int(*array_p)[4] = NULL; //直接定义一个数组指针
	array_p = &array;
	for (i = 0; i < 4; i++) {
		(*array_p)[i] = 20 - i;
	}
	printf("\n");
	for (i = 0; i < 4; i++) {
		printf("%d\n", array[i]);
	}
	return 0;
}