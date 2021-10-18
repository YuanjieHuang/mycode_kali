#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	int a[10] = { 0 };
	int i = 0;
	int j = 0;
	// a 是数组名  a++,,,, a = a +１; a[1];  *(a+1)　//数组名是一个常量， 是一个常指针，不能够被修改  ,指向首元素
	/*
		a + 1   a是 int *const a;  a +1   4 个字节的偏移
		&a +1  &a  int[10] * a     &a+1  4 *10 = 40 个字节的偏移
	*/
	int aa[3][4] = { 
		{ 3, 5, 4, 3 },
		{2,3,4,5}
	};
	// aa ,int[4]类型的地址
	//初始化一个数组，不管是几维的， 如果初始化不完全， 剩下的就全部填充0
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", aa[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	int size = sizeof(aa); //在求一个二维数组的 数据类型大小  int   [3][4][5]
	printf("size = %d\n", size);
	// 比较好理解的方法 (int   [3][4])  * p = NULL;
	int(*p)[3][4] = NULL;//指向二维数组 int[3][4]的指针
	printf("p : 0x%p, p + 1 : 0x%p\n", p, p + 1);
	printf("p : %d, p + 1 : %d\n", p, p + 1);
	//数组也是有数据类型的
	return 0;
}