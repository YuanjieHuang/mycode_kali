#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//二级指针作为输出参数
//在函数内部 在堆上开辟空间  传出去。
int get_mem(/*out */char **mem1, int *mem_len1, char **mem2, int *mem_len2)
{
	char *temp_p1 = NULL;
	char *temp_p2 = NULL;
	int len1 = 0;
	int len2 = 0;
	if (mem1 == NULL || mem2 == NULL || mem_len1 == NULL || mem_len2 == NULL) {
		fprintf(stderr, " (mem1 == NULL || mem2 == NULL || mem_len1 == NULL || mem_len2 == NULL) \n");
		return -1;
	}
	temp_p1 = (char *)malloc(4096);
	if (temp_p1 == NULL) {
		return -1;
	}
	memset(temp_p1, 0, 4096);
	strcpy(temp_p1, "12345678");
	len1 = strlen(temp_p1);
	temp_p2 = (char*)malloc(4096);
	if (temp_p2 == NULL) {
		return -1;
	}
	memset(temp_p2, 0, 4096);
	strcpy(temp_p2, "abcdefg");
	len2 = strlen(temp_p2);
	//以上开辟完空间
	*mem1 = temp_p1;
	*mem2 = temp_p2;
	*mem_len1 = len1;
	*mem_len2 = len2;
	return 0;
}
void free_mem(char **mem1, char **mem2)
{
	char *temp_mem1 = *mem1;
	char *temp_mem2 = *mem2;
	if (mem1 != NULL) {
		free(temp_mem1);
	}
	if (mem2 != NULL) {
		free(temp_mem2);
	}
	*mem1 = NULL;
	*mem2 = NULL;
}
int main(void)
{
	char *buf1 = NULL;
	char *buf2 = NULL;
	int len1 = 0;
	int len2 = 0;
	if (get_mem(&buf1, &len1, &buf2, &len2) < 0) {
		return -1;
	}
	printf("buf1: %s, buf2:%s\n", buf1, buf2);
	free_mem(&buf1, &buf2);
	return 0;
}