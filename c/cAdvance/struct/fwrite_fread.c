#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILE_NAME  "./test5.txt"
struct teacher
{
	int age;
	int id;
	char *name;  
	int name_len;
};
void showStruc(struct teacher * struc)
{
	if(NULL != struc)
	{
		printf("age:%d\t",struc->age);
		printf("id :%d\t" ,struc->id);
		printf("name_lenth:%d\t",struc->name_len);
		printf("name:%s\n",struc->name);
	}
}
int my_write()
{
	FILE *fp = NULL;
	int write_ret = 0;
	fp = fopen(FILE_NAME, "wb+");
	if (fp == NULL) {
		fprintf(stderr, "fopen error\n");
		return -1;
	}
	struct  teacher t1;
	char *name = "zhang3";
	t1.age = 10;
	t1.id = 20;
	t1.name = malloc(64);
	memset(t1.name, 0, 64);
	strcpy(t1.name, name);
	t1.name_len = strlen(name);
	showStruc(&t1);
	//将数据结构写进去
	write_ret = fwrite(&t1, sizeof(struct teacher), 1, fp);
	if (write_ret < 0) {
		fprintf(stderr, "write error\n");
		return -1;
	}
	write_ret = fwrite(t1.name, t1.name_len, 1, fp);
	if (write_ret < 0) {
		fprintf(stderr, "write error\n");
		return -1;
	}
	if (fp != NULL) {
		fclose(fp);
	}
	return 0;
}

int  my_read()
{
	FILE *fp = NULL;
	//以下读操作
	struct teacher t2 = { 0 };
	int read_ret = 0;
	fp = fopen(FILE_NAME, "wb+");
	if (fp == NULL) {
		fprintf(stderr, "fopen r+error\n");
		return -1;
	}
	//读出了结构体
	read_ret = fread(&t2, sizeof(struct teacher), 1, fp);
	if (read_ret < 0) {
		fprintf(stderr, "fread error\n");
		fclose(fp);
		return -1;
	}
	t2.name = malloc(t2.name_len + 1);
	memset(t2.name, 0, t2.name_len + 1);
	read_ret = fread(t2.name, t2.name_len, 1, fp);
	if (read_ret < 0) {
		fprintf(stderr, "fread error\n");
		fclose(fp);
		return -1;
	}
	printf("id : %d, age : %d, name:%s, name_len :%d\n", t2.id, t2.age, t2.name, t2.name_len);
	if (fp != NULL)
	{
		fclose(fp);
	}
	return 0;
}

int main(void)
{
	my_write();
	my_read();
	return 0;
}