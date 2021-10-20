// #pragma	pack(2)					//8字节对⻬
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct	A
{
	char					c;					//1byte
	double				d;					//8byte
	short					s;					//2byte
	int					i;					//4byte
};

struct B
{
	int a;
	//double d;
	char c1;
	char c2;
	short s1;
	short s2;
};

int main(void)
{
	printf("int:%d double:%d long:%d\n",sizeof(int),sizeof(double),sizeof(long));
	int size_A = 0;

	size_A = sizeof(struct A);

	printf("size_A : %d\n", size_A);

	int size_B = 0;
	size_B = sizeof(struct B);

	printf("size_B : %d\n", size_B);


	return 0;
}