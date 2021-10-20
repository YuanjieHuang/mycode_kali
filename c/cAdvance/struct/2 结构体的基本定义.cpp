#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//1
struct teacher
{
	int id;
	char name[64];
};

struct teacher t5 = { 5, "laoshi5" };

//2
struct {
	int id;
	char name[64];
} t3, t4;//匿名的结构体类型  类型只能定义一次， 不能通过函数传参


//3
typedef struct  _teacher
{
	int id;
	char name[64];
} teacher_t;  //最常用的写法


void print_teacher(struct teacher* p1)
{
	printf("id = %d\n", p1->id);
	printf("name = %s\n", p1->name);
}

void print_teacher2(struct teacher t) //t = t1     int a = b; struct teacher t1 = t2
{
	printf("===== print_teacher2===\n");
	printf("id = %d\n", t.id);
	printf("name = %d\n", t.name);
}

void copy(struct teacher to, struct teacher from)
{
	to = from;
}

void copy2(struct teacher *to, struct teacher *from)
{
	*to = *from;
}

int main(void)
{
	struct teacher  t1;
	struct teacher  t8;
	teacher_t t6 = {6, "laoshi6"};
	//teacher t7;  // C语言中  定义一个结构体 必须加上struct 关键字  C++不用加

	t1.id = 10;
	strcpy(t1.name, "laoshi1");

	print_teacher(&t1);
	print_teacher(&t5);

	print_teacher2(t1);  //

	printf("=====\n");
	copy2(&t8, &t1);
	print_teacher(&t8);

	struct teacher t9 = t1; //int a = b;
	print_teacher(&t9);
	struct teacher t10; //int a = b;
	copy(t10,t1);
	print_teacher(&t9);


	return 0;
}