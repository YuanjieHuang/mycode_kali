#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME "c:/test/test1.txt"
#define FILE_NAME2 "c:/test/test5.txt"

int get_file_size(const char *file_name)
{
	FILE *fp = NULL;
	int pos_begin = 0;
	int pos_end = 0;

	fp = fopen(file_name, "r+");
	if (fp == NULL) {
		fprintf(stderr, "open %s error\n", file_name);
		return -1;
	}

	//将文件内部的指针 一到头部
	fseek(fp, 0, SEEK_SET);

	pos_begin = ftell(fp);

	//将文件内部指针 移到 尾部
	fseek(fp, 0, SEEK_END);
	pos_end = ftell(fp);

	return pos_end - pos_begin;
}

int main(void)
{
	FILE *fp = NULL;

	fp = fopen(FILE_NAME, "r+");
	if (fp == NULL) {
		return -1;
	}

	int pos = 0;
	int ret = 0;
	char ch = 0;

	ret = fseek(fp, 3, SEEK_SET);  //SEEK_SET就表示文件开头
	if (ret < 0) {
		return -1;
	}
	pos = ftell(fp);
	printf("pos = %d\n", pos);

	ch = fgetc(fp);
	printf("ch:%c\n", ch);

	pos = ftell(fp);
	printf("pos = %d\n", pos);


	fseek(fp, 0, SEEK_CUR); // 让内部的指针依然指向5

	if (fputc('Y', fp) == EOF)
	{
		printf("fputc X error\n");
	}

	pos = ftell(fp);
	printf("pos = %d\n", pos);

	fseek(fp, 0, SEEK_END); //将内部的指针偏移到 文件尾部
	if (fputc('Z', fp) == EOF)
	{
		printf("fputc Z error\n");
	}

	pos = ftell(fp);
	printf("pos = %d\n", pos);

	if (fp != NULL) {
		fclose(fp);
	}



	int file_size = 0;

	file_size = get_file_size(FILE_NAME2);

	printf("file _size = %d\n", file_size);

	return 0;
}