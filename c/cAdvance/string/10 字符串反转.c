#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int inverse2(char *src, char *outbuf)  //outbuf = outbuf
{
	if (src == NULL || outbuf == NULL) {
		return -1;
	}

	if (*src == '\0') {
		return 0;
	}

	inverse2(src + 1, outbuf);

	strncat(outbuf, src, 1);

	return 0;
}



//使用全局变量
char g_buf[128] = { 0 };

//倒叙打印str字符串
int inverse(char *str)
{
	if (str == NULL) {
		return -1;
	}

	if (*str == '\0') {
		return 0;
	}

	inverse(str + 1);//bcdefg

	//printf("%c", *str);
	strncat(g_buf, str, 1);
	
	return 0;
}

#if 0
int inverse(char *str)
{
	char *begin = str;
	char *end = str + strlen(str) - 1;
	char tmp = 0;

	if (str == NULL) {
		fprintf(stderr, " str == NULL\n");
		return -1;
	}

	while (end > begin) {
		tmp = *end;
		*end = *begin;
		*begin = tmp;
		begin++;
		end--;
	}

	return 0;
}
#endif

int main(void)
{
	char str[] = "abcdefghi";
	char out_buf[128] = { 0 };


	inverse(str); //abcdefg
	printf("g_buf : %s\n", g_buf);

	//printf("str : %s\n", str);


	inverse2(str, out_buf);
	printf("out_buf : %s\n", out_buf);



	return 0;
}