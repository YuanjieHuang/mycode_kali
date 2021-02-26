#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a = 12;
	//0000 1100
	int b = 7;
	//0000 0111


	int x = 0;

	x = a&b;
	//0000 0100
	printf("%d\n", x);

	x = a | b;
	//0000 1111
	printf("%d\n", x);

	x = a^b;
	//0000 1011
	printf("%d\n", x);

	printf("=====\n");

	//char value = 0xff; //1111 1111
	unsigned char value = 0xff;
	unsigned char value1 = value << 2;
	printf("value << 2: 0x%x\n", value1);

	int value2 = 0xffffff00; //有符号类型补1
	printf("value2 >> 2: 0x%x\n", value2 >> 2);

	int value3 = 0x3fffff00;//0011 1111 1111 1111 00000000
	int value4 = value3 >> 2;//0000 1111 1111   1100
	printf("value3 >> 2: 0x%x\n", value4);

	unsigned int value5 = 0xffffff00; //1111111 
													//0011 
	printf("value5>>2: 0x%x\n", value5 >> 2);

	unsigned int value6 = 0xffffffff;


	unsigned int value7 = 0xff00ff00;
	//1111 1111 0000 0000 1111 1111 0000 0000
	unsigned int mask = 0xffff00ff;
	//1111 1111 1111 1111 0000 0000 1111 1111


	unsigned int value8;// 0xff000000;

	value8 = value7&mask;
	printf("value8 = 0x%x\n", value8);

	return 0;
}