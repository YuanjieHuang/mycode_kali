#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


typedef struct student  //给一个数组类型 起别名
{
	char name[64];
	int age;
} student_t;

//int g_a = 10;


typedef  unsigned int u32;
typedef unsigned long u64;


int main(void)
{
	int a = 10; //int 就是告诉编译器 开辟固定大小4个字节的内存块
	double b = 1.30;//就是告诉编译器 开辟固定大小8个字节的内存块
	char c = 'c';
	//数据类型的他的本质是  固定大小内存看的别名

	a = 30;

	int * p = &a;  //p是一个指针， 指向a的地址， 
	char *pp = &c;

	int b_array[10] = { 0 }; //定义一个数组  

	printf("sizeof(p) :%d\n", sizeof(p));   //求 int* 数据类型的大小  4
	printf("sizeof(pp) :%d\n", sizeof(pp));//求char*数据类型的大小 4
	printf("sizeof(*p):%d\n", sizeof(*p)); // 求int数据类型的大小 4
	printf("sizeof(*pp):%d\n", sizeof(*pp));//求 char数据类型的大小 1
	
	printf("p : %p, p+1: %p\n", p, p + 1);     //指针的数据类型 根据指针的跨度来决定的
	printf("pp : %p, pp+1: %p\n", pp, pp + 1);
	 
	//int---4
	//double --8
	//int * ---4;
	//int[10]  ----40
	//求数组类型的大小 sizeof
	printf("sizeof(b_array) :  %d\n", sizeof(b_array));  //求 int b_array[10]数据的大小
	printf("sizeof(b_array[0]): %d\n", sizeof(b_array[0])); //求int这种数据类型的大小

	printf("&b_array:%p, b_array:%p, &b_array+1: %p, b_array+1: %p", &b_array, b_array, &b_array + 1, b_array + 1);
	
	//b_array 他是数组首元素的地址，首元素是int类型 b_array的数据类型 int*
	//&b_array 他是数组(int[10])的地址, 此数组的类型 int[10]  ,, &b_array->  (int[10]) *

	student_t s1; //分配 68 的字节内存块
	student_t *sp = &s1; 
	//g_a = 30;
	u32 aa;

	printf("sizeof(student_t) : %d\n", sizeof(s1));
	//sp + 1; sp

//	void a;
	void * //是一种数据类型  * 标志的是指针， void  万能


	return 0;
}


