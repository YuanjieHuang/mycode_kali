#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct teacher
{
	int id;
	char name[64];
	int age;
};

int main(void)
{
	struct teacher t1 = {0};
	struct teacher *p = &t1;

	int age = t1.age;
	int id = t1.id;

	int id_offsize = (int)&(((struct teacher *)0)->id);
	int name_offsize = (int)&(((struct teacher *)0)->name);
	int age_offsize = (int)&(((struct teacher *)0)->age);

	printf("id_off: %d, name_off:%d, age_off:%d\n", id_offsize, name_offsize, age_offsize);

	int age_off = (int)(&(p->age)) - (int)p;

	printf("age_off : %d\n", age_off);

	return 0;
}