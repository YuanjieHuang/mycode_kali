#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME_LEN  64

struct teacher
{
	int id;
	char *name;
};


//如果结构体中有指针 在堆上开辟的空间
//以下这个拷贝函数， 就是浅拷贝
//结构体可以通过变量直接赋值， 但不要使用这种方法， 
//要给结构体中的成员 一个一个拷贝
void copy_teacher(struct teacher *to, struct teacher *from)
{
	*to = *from;
}

void copy_teacher_deep(struct teacher *to, struct teacher *from)
{
	to->name = (char*)malloc(NAME_LEN);
	memset(to->name, 0, NAME_LEN);
	strcpy(to->name, from->name);

	to->id = from->id;
}


void print_teacher(struct teacher *tp)
{
	printf("id : %d, name : %s\n", tp->id, tp->name);
}

int main(void)
{
	struct teacher tp1 = {0}; //在栈上开辟的一个teacher结构体
	struct teacher tp2 = {0};

	tp1.id = 1;
	tp1.name = (char*)malloc(NAME_LEN);
	memset(tp1.name, 0, NAME_LEN);
	strcpy(tp1.name, "zhang3");

	copy_teacher(&tp2, &tp1);
	// copy_teacher_deep(&tp2, &tp1);

	print_teacher(&tp1);
	tp1.name = "lisi";
	print_teacher(&tp2);

	if (tp1.name != NULL) {
		free(tp1.name);
		tp1.name = NULL;
	}

	if (tp2.name != NULL) {
		free(tp2.name);
		tp2.name = NULL;
	}



	return 0;
}