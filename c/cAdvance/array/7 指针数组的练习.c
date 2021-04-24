#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
#define	NUM(a)	(sizeof(a)/sizeof(*a))
char*	keywords[]	=	{
"while",
"case",
"static",
"do"
};
int	searcheKeyTable(const char*	table[],	const int	size,
const char*	key,	int	*pos);
*/


int	searcheKeyTable(const char*	table[], const int	size, const char*	key, int	*pos)//table = keywords
{
	int i = 0;
	int ret = 0;

	if (table == NULL || key == NULL || pos == NULL) {
		return -1;
	}

	for (i = 0; i < size; i++) {
		if (strcmp(table[i], key) == 0) {
			//找到了匹配的key
			*pos = i;
			ret = i;
			break;
		}
	}

	if (i == size) {
		//没找到key
		*pos = -1;
		ret = -1;
	}

	return ret;
}


int main(void)
{
	char*	keywords[] = {  // char* keywords[4]  (char*)[4]  ==> 16
		"while",
		"case",
		"static",
		"do",
		NULL
	};

	int i = 0;
	int num = 0;
	int pos = 0;

	num = sizeof(keywords) / sizeof(*keywords); //16 / 4 = 4;

	searcheKeyTable(keywords, num, "do", &pos);

	if (pos < 0) {
		printf("未找到 while \n");
		return -1;
	}
	printf("do 在 第%d 个位置\n", pos+1);
	for (i = 0; keywords[i] != NULL; i++) {
		printf("%s\n", keywords[i]);
	}


	return 0;
}