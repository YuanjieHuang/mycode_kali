#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
src 源字符串
dst 目标地址
*/
int  str_copy1(char *dst, char *src)
{
	for (; *src != '\0'; src++, dst++) {
		*dst = *src;
	}
	*dst = '\0';

	return 0;
}

int str_copy2(char *dst, char *src)
{
	for (; *src != '\0';) {
		*dst++ = *src++; // *dst = *src, dst++, src++
	}
	*dst = '\0';


	return 0;
}

int str_copy3(char *dst, char *src)
{
	// src: "1234567\0"
	// dst:  1234567\0

	for (; (*dst = *src) != '\0';     ) {
		src++;
		dst++;
	}

	return 0;
}

int str_copy4(char *dst, char *src)
{
//	for (; (*dst++ = *src++););
	while ((*dst++ = *src++));


	//打日志
	printf("dst : %s\n", dst);

	return 0;
}

int str_copy5(/*out */char *dst, /*in */ const char *src)
{
	char *temp_dst = NULL;
	char *temp_src = NULL;
	int retn = 0; //返回变量


	//先对参数进行合法判断
	if (dst == NULL || src == NULL) {
		fprintf(stderr, "  dst == NULL || src == NULL \n");
		retn = -1;
		goto END;
	}

	for (temp_dst = dst, temp_src =(char*)src; (*temp_dst++ = *temp_src++);)
	{
	}

	printf("in str_copy5: dst = %s\n", dst);


END:
	return retn;
}

//           0x00000000 ---> NULL     ===   0  ==== '\0' ==>0      '0' ===> 48

int main(void)
{
	char *str = "123456789";
	char dst[128] = { 0 };
	char *dst = NULL;

	str_copy5(dst, str);
	//str_copy5(NULL, str);

	printf("dst : %s\n", dst);

	return 0;
}