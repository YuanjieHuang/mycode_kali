#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct	A
{
	int					a1 : 5;
	int					a2 : 9;
	char				    c;
	int					b : 4;
	short			        s;
};

struct B
{
	int a : 7;
	int a2 : 5;
	int a3 : 18;
	int a4 : 4;
	char e : 7;
	int x;
};

int main(void)
{

	int size_A = 0;
	int size_B = 0;


	size_A = sizeof(struct A);
	printf("%d\n", size_A);
	size_B = sizeof(struct B);
	printf("%d\n", size_B);

	return 0;
}