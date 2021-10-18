#include <iostream>

using namespace std;

//2 对全局变量的检测能力加强， 一个变量不管是声明，还是定义，只能出现一次
int g_val ; //全局变量
//int g_val = 10;// 右一个全局变量

struct student
{
	int id;
	char name[64];
};
void showStudent(const student *s)
{
	printf("id:%5d\t",   s->id);
	printf("name:%s\n",s->name);
}
void change_stu(struct student *s)
{
	s ->id = 10;
	showStudent(s);
}

void change_stu2(const struct student *s)
{
	//s->id = 10; //此时s所指向的区域是一个常量 不能够被修改
	struct student s2={10265889,"jiege"};
	s = &s2;
	showStudent(s);
}

void change_stu3(struct student *const s)
{
	s->id = 1111;
	//struct student s2;
	//s = &s2;  //s是一个常量指针
	showStudent(s);
}

void change_stu4(const struct student *const s)
{
	// s->id = 10;
	// struct student s2;
	// s = &s2;  //s是一个常量指针
	// showStudent(s);
}

int main(void)
{
	student s={0};
	change_stu (&s);
	change_stu2(&s);
	change_stu3(&s);
	change_stu4(&s);
	return 0;
}