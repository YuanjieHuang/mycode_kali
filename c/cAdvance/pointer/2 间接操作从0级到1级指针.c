#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//void swap(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}


//得到一个文件的长度
void get_file_len(int file_len)
{
	file_len = 30;
}


//如果不使用指针，想要将子函数中的数据传出来，那么一定要有 返回值， 发生值拷贝
int get_file_len2()
{
	int file_len = 0;

	file_len = 30;

	return file_len;
}

//通过指针， 在函数内部间接的修改函数外部的变量， 这个是指针的间接操作的意义
int get_file_len3(int *p)
{
	*p = 30;

	return 0;
}

int main(void)
{
	int a = 10;
	int b = 20;

	int file_len = 0;

	//swap(a, b);

	get_file_len(file_len);

	file_len = get_file_len2();


	get_file_len3(&file_len);



	return 0;
}