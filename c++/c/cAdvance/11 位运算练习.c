#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getCnt(unsigned int num)
{
	int cnt = 0;

	for (; num != 0; num = num >> 1) {
		if ((num & 0x1) == 1) {
			cnt++;
		}
	}

	return cnt;
}

int main(void)
{                                           //00000000000000000000000000000000000000000
	unsigned int	i = 0xcffffff3; //1100 1111 1111 1111 1111 1111 1111 1111 0011
	                                          //            &                                                       1   1&1 = 1 , 0 & 1 = 0

	int cnt = 0;
	cnt = getCnt(i);
	printf("cnt : %d\n", cnt);
}