#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void make_array(int (*a)[5], int row, int col)
//void make_array(int a[3][5])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			a[i][j] = i + j;
		}
	}
}

void print_array(int (*a)[5], int row, int col)
//void print_array(int a[3][5]) // print_array:a[3][5]  = main:a[3][5]
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("a[%d][%d]: %d  ", i, j, a[i][j]);

		}
		printf("\n");
	}
	printf("\n");
}

typedef int(ARRAY_5_6)[5][6];

void make_array2(ARRAY_5_6 *b, int row, int col, int height)
//void make_array2(int b[3][5][6], int row, int col, int height)
//void make_array2(int(*b)[5][6], int row, int col, int height)
{
	int i = 0, j = 0, k = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			for (k = 0; k < height; k++) {
				//b[i][j][k] = i + j + k;
				*(*(*(b + i) + j) + k) = i + j + k;
			}
		}
	}
}

void print_array2(ARRAY_5_6 *b, int row, int col, int height)
{
	int i = 0, j = 0, k = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			for (k = 0; k < height; k++) {
				printf("b[%d][%d][%d]:%d  ", i, j, k, b[i][j][k]); 
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
}

void print_array3(int *p, int num)
{
	int i = 0;
	for (i = 0; i < num; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
}

int main(void)
{
	int a[3][5]; //数组无论是几维数组， 都是一块连续的内存空间

	int b[3][5][6];


	make_array(a, 3 ,5);
	print_array(a, 3, 5);

	printf("------\n");

	make_array2(b, 3, 5, 6);
	print_array2(b, 3, 5, 6);
	printf("------\n");


	print_array3((int *)a, 15);

	return 0;
}