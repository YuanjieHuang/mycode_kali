#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int getBit(unsigned int x, int pos, int n)
{
	return (x >> pos) & ~((~0 << n));
}


int main(void)
{
	unsigned x = 0xff30ff30;

	unsigned int result = 0;

	result = getBit(x, 16, 8);

	printf("%x\n", result);



	return 0;
}