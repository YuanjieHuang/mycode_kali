#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int g_val; //全局变量
int g_val = 10;// 右一个全局变量

typedef struct teacher
{
	int id;
	char name[64];
}teacher_t;

void f(int i)
{
	printf("i = %d\n", i);
}

g()
{
	return 10;
}

//3 C语言中的逻辑是与非 
void test3()
{
	int flag = 0; // C语言中 数值0表示为假
//	int flag = 1; // C语言中 数值非0表示真  C语言中是通过数值是否为0 来分辨逻辑真假的。
	 
}

//4 三目运算符的增强
void test4()
{
	int a = 10;
	int b = 20;

	int min_value = 0;


	//min_value = (a < b ? a : b);  
	//(a < b ? a : b) = 30;//返回的是一个数值， 10  ， 10 = 30

	*(a < b ? &a : &b) = 30;

	//*(a < b ? &10 : &b) = 30; //10 =30

	
	printf("%d\n", a);
}


//5 c语言中的const 
void test5()
{
	const int a ;
	//int const b; //const int , int const 是等价的

	int *p = (int*)&a;
	*p = 20;//C语言中可以通过指针的间接赋值改变const变量 

	printf("a = %d\n", a);
}

#define A (3)
#define B (4)

void test6()
{
	int const a = 3;
	int const b = 4; //再次说明 c语言中的 const 并不是一个常量，是一个变量 加了只读属性。

	int array[A+ B] = { 0 }; //数组类型大小是固定， 将两个变量做长度，编译器无法确定长度
}

enum season {
	SPR = 0,
	SUM,
	AUT,
	WIN
};

void test7()
{
	enum season s = SPR;

	s = 0;
	s = 1;
	s = 2;  // C语言对枚举类型的赋值， 是可以通过枚举的值，直接赋值的。
	s = 136; //136  什么意思？

}

//1 实用性增强
int main(void)
{
	//struct teacher t1; //在C语言中如果使用一个struct 复杂类型，那么必须将struct 关键字写进来
	//teacher_t t2;
	//printf("%d\n", g_val);

	//f(1,2,3);//warning

	//int value = 0;
	//value = g(1, 2, 3, 4, 5);

	//printf("%d\n", value);
	
	//test4();
	//test5();
	test7();
	return 0;
}