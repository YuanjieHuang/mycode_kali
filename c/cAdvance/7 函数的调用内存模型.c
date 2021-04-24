#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* func_2(char *buf)
{
	//printf("in func2: main's stack memory: %s\n", buf);
	//printf("in func2: main's heap memory: %s\n", buf);
	//printf("in func2: func_1's stack memory: %s\n", buf);

	char *func_2_buf = "1234567";

	//子函数2 在堆中开辟的内存
	//func_2_buf = malloc(128);
	//if (func_2_buf == NULL) {
	//	return NULL;
	//}

	//strcpy(func_2_buf, "func2: xxxxxxxxx");


	return func_2_buf;
}



char* func_1(char *buf)
{
	//char func_buf_1[128] = { 0 };
	
	//strcpy(func_buf_1, "func_1: xxxxxxx");
	//printf("in func1: main's stack memory: %s\n", buf);
	//printf("in func1: main's heap memory: %s\n", buf);

	char *func_1_buf = NULL;

	func_1_buf = func_2(func_1_buf);
	printf("in func1: func2 global memory : %s\n", func_1_buf);

	return func_1_buf;
}

int main(void)
{
	//char buf[128] = { 0 };//main函数在栈上开辟了空间
	char *buf = NULL;

	//buf = malloc(128);//在堆上开辟空间
	//if (buf == NULL) {
	//	return -1;
	//}


	//strcpy(buf, "xxxxxxxxxx");

	//main 函数使用子函数在栈上开辟的内存
	buf = func_1(buf);
	printf("in main: func2 global memory : %s\n", buf);


	//printf("in main: func_1 's stack memory: %s\n", buf);


	//if (buf != NULL) {
	//	free(buf);
	//	buf = NULL;
	//}


	return 0;
}