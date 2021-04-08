#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct teacher
{
	int id;
	char name[64];
};

//开辟 struct teacher 的空间
void create_teachers(struct teacher **tpp, int num)
{
	struct teacher *p = NULL;

	if (tpp == NULL) {
		return;
	}

	p = (struct teacher *)malloc(sizeof(struct teacher) *num);
	if (p == NULL) {
		return;
	}

	*tpp = p;

	return;
}

void print_teachers(struct teacher *tp, int num)
{
	int i = 0;
	printf("=======\n");
	for (i = 0; i < num; i++) {
		printf("id :%d\n", tp[i].id);
		printf("name : %s\n", tp[i].name);
	}
}

void free_teachers(struct teacher **tpp)
{
	if (tpp == NULL) {
		return;
	}

	struct teacher *tp = *tpp;

	if (tp != NULL) {
		free(tp);
		*tpp = NULL;
	}

	return;
}

int main(void)
{
	struct teacher * tp = NULL;
	int i = 0;
	int num = 3;


	create_teachers(&tp, num);
	for (i = 0; i < num; i++) {
		printf("enter %d 's id: ", i + 1);
		scanf("%d", &tp[i].id);
		printf("enter %d's name:", i + 1);
		scanf("%s", tp[i].name);
	}

	print_teachers(tp, num);

	free_teachers(&tp);


	if (tp == NULL) {
		printf("freed succ!\n");
	}




	return 0;
}