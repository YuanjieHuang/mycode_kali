#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int get_non_space_cnt(/*in */char *str,/*out*/ int *cnt_p)
{
	char *p = NULL;
	char *q = NULL;

	int cnt = 0;

	

	if (str == NULL || cnt_p == NULL) {
		fprintf(stderr, " str == NULL || cnt_p == NULL \n");
		return -1;
	}

	p = str;//指向字符串首元素
	q = str + strlen(str) - 1; //指向字符串的末尾元素

	//左边遍历
	//while ((*p == ' ' && *p !='\0')  ) {
	while (isspace(*p) && *p != '\0') 
	{
		p++;
	}

	//while ((*q == ' ') && (q > p))
	while (isspace(*q) && (q >p) ) 
	{
		q--;
	}

	cnt = q - p + 1;

	*cnt_p = cnt;

	return 0;
}

int main(void)
{
	char *str = "            ";
	int cnt = 0;

	get_non_space_cnt(str, &cnt);

	printf("cnt = %d\n", cnt);

	return 0;
}