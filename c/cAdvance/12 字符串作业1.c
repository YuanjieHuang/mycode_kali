#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
有字符串有以下特征（“abcd11111abcd2222abcdqqqqq”）,求写一个函数接口，
输出以下结果。
把字符串替换成（dcba11111dcba2222dcbaqqqqq），并把结果传出。
要求：
1. 正确实现接口和功能
2. 编写测试用例
/*
src:				原字符串
dst:				⽣成的或需要填充的字符串
sub:				需要查找的⼦字符串
new_sub:提换的新⼦字符串
return	:	0	成功
-1	失败
*/


int	replaceSubstr(/*	in	*/char	*src,	/*	out	*/char**	dst,
	/*	in	*/char	*sub,		/*	in	*/char	*new_sub)
{
	char *out = NULL;
	char *p = NULL; 
	char *q = NULL; 
	int sub_len = 0;
	int new_sub_len = 0;

	if (src == NULL || dst == NULL || sub == NULL || new_sub == NULL) {
		fprintf(stderr, "(src == NULL || dst == NULL || sub == NULL || new_sub == NULL)\n");
		return -1;
	}
	out = (char*)malloc(sizeof(char)* 4096);
	if (out == NULL) {
		fprintf(stderr, "malloc out error\n");
		return -1;
	}
	memset(out, 0, 4096);

	p = src;
	q = p;
	sub_len = strlen(sub);
	new_sub_len = strlen(new_sub);


	while (  (p = strstr(p, sub)) != NULL) {
		//找到了子串
		strncat(out, q, p - q);
		strncat(out, new_sub, new_sub_len);
		
		p += sub_len;
		q = p;
		if (*p == '\0') {
			break;
		}
	}

	if (*q != '\0') {
		strncat(out, q, (src+strlen(src) - q));
	}

	*dst = out;
	
	return 0;
}

int main(void)
{
	char *str = "abcd213213abcddjisoabcd2131abcd";
	char *dst = NULL;

	replaceSubstr(str, &dst, "abcd", "X");

	printf("dst: %s\n", dst);

	return 0;
}