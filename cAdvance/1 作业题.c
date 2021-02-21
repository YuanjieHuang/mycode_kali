#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IN
#define OUT


void free_mem(char ***array_p, int num) // char ****array = &p
{
	char **array = *array_p;
	int i = 0;

	if (array_p == NULL) {
		return;
	}

	if (array == NULL) {
		return;
	}

	for (i = 0; i < num; i++) {
		if (array[i] != NULL) {
			free(array[i]);
			array[i] = NULL;
		}
	}

	free(array);

	*array_p = NULL;
}

int sort(IN char *array_1[], int num1,
	IN char(*array_2)[30], int num2,
	OUT char ***array_3_p, OUT int *num3_p)
{
	char **p= NULL;
	int num3 = 0;
	int retn = 0;
	int i = 0;
	int j = 0;
	int len = 0;
	char *temp_p = NULL;

	if (array_1 == NULL || array_2 == NULL || array_3_p == NULL || num3_p == NULL) {
		fprintf(stderr, "array_1 == NULL || array_2 == NULL || array_3_p == NULL || num3 == NULL\n");
		return -1;
	}

	num3 = num1 + num2; //这个是p3指针所需要第一次开辟的 指针的个数
	p = (char**)malloc(sizeof(char*)*num3);
	if (p == NULL) {
		fprintf(stderr, "malloc char**p3 error\n");
		retn = -1;
		goto END;
	}
	memset(p, 0, sizeof(char*)*num3);

	//array_1 copy p中
	for (i = 0; i < num1; i++) {
		len = strlen(array_1[i]);
		p[i] = (char*)malloc(sizeof(char)* (len + 1));
		memset(p[i], 0, sizeof(char)*(len + 1));
		strcpy(p[i], array_1[i]);
	}

	//array_2 copy p中
	for (j = 0; j < num2; j++, i++) {
		len = strlen(array_2[j]);
		p[i] = (char*)malloc(sizeof(char)*(len + 1));
		memset(p[i], 0, sizeof(char)*(len + 1));
		strcpy(p[i], array_2[j]);
	}

	for (i = 0; i < num3; i++) {
		printf("p[%d]:%s\n", i, p[i]);
	}
	//对 p 排序

	for (i = 0; i < num3; i++) {
		for (j = i; j < num3; j++) {
			if (strcmp(p[i], p[j]) > 0) {
				temp_p = p[i];
				p[i] = p[j];
				p[j] = temp_p;
			}
		}
	}
	printf("----\n");
	for (i = 0; i < num3; i++) {
		printf("p[%d]:%s\n", i, p[i]);
	}

	*array_3_p = p;
	*num3_p = num3;

END:
	if (retn != 0) {
		free_mem(&p, num3);
	}
	return 0;
}


int main(void)
{
	int ret = 0;

	char *p1[] = { "aa", "cccccc", "bbbbb" };
	char buf2[10][30] = { "111111", "3333", "2222" };
	char **p3 = NULL;

	int len1, len2,len3, i = 0;

	len1 = sizeof(p1) / sizeof(*p1);
	len2 = 3;

	sort(p1, len1, buf2, len2, &p3, &len3);


	free_mem(&p3, len3);

	if (p3 == NULL) {
		printf("free p3 succ\n");
	}




	return 0;
}