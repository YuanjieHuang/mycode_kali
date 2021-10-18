#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef unsigned int u32;
int main(void)
{
	//int a[10];
	typedef int (ARRAY_INT_10) [10]; //为 int【10】这种数组 起一个别名 ARRAY_INT_10
	ARRAY_INT_10 b_array; //int b_array[10];  int *a    int (*a)[10] = &b_array;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		b_array[i] = i;
	}
	for (i = 0; i < 10; i++) {
		printf("%d\n", b_array[i]);
	}
	//(int[4]) (* pointer);
	int(*pointer)[4];
	ARRAY_INT_10 * p = &b_array;
	printf("p : %d, p+1 : %d", p, p + 1);
	return 0;
}