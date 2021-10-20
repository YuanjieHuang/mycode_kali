#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
	有一个字符串开头或结尾含有n个空格
	（” abcdefgdddd ”），
	欲去掉前后空格，返回一个新字符串。
	要求1：请自己定义一个接口（函数），并实现功能；
	要求2：编写测试用例。
	int trimSpace(char *inbuf, char *outbuf);
*/

int trimSpace(char *inbuf, char *outbuf)
{
	int i = 0;
	int j = 0;
	int len = 0;

	if (inbuf == NULL || outbuf == NULL) {
		fprintf(stderr, " (inbuf == NULL || outbuf == NULL)\n  ");
		return -1;
	}

	j = strlen(inbuf) - 1;

	//左边开始遍历
	while (isspace(inbuf[i]) && inbuf[i] != '\0') {
		i++;
	}

	//右边
	while (isspace(inbuf[j]) && j > i) {
		j--;
	}

	len = j - i + 1;

	strncpy(outbuf, inbuf + i,len);
	outbuf[len] = '\0';

	return 0;
}


int main(void)
{
	printf("%d",isspace('\0'));
	char *str = "   abcdefgdddd   ";
	char buf[128] = { 0 };

	if (trimSpace(str, buf) < 0) {
		fprintf(stderr, " trimSpace err\n ");
		return -1;
	}

	printf("buf: [%s]\n", buf);

	return 0;
}