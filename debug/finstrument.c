#include <stdio.h>
#include <stdlib.h>
 
int func(int a, int b)
{
	return a + b;
}
 
static inline void print(int n)
{
	printf("%d\n", n);
}
 
int main()
{
	func(3, 4);
	print(func(3,4));
	return 0;
}
