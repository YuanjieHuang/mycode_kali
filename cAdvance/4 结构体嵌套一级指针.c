#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define  NAME_LEN		(64)

struct teacher
{
	int id;
	char *name;
};


int create_teachers(struct teacher **tpp, int num)
{
	struct teacher *tp = *tpp;
	int i = 0;

	if (tpp == NULL) {
		return -1;
	}

	tp = (struct teacher*)malloc(sizeof(struct teacher) *num);
	if (tp == NULL) {
		fprintf(stderr, "malloc tp error\n");
		return -1;
	}
	memset(tp, 0, sizeof(struct teacher) * num);

	for (i = 0; i < num; i++) {
		tp[i].name = (char*)malloc(sizeof(char)*NAME_LEN);
		memset(tp[i].name, 0, sizeof(char)*NAME_LEN);
	}

	*tpp = tp;

	return 0;
}

void print_teacher(struct teacher* p, int num)
{
	int i = 0;

	for (i = 0; i < num; i++) {
		printf("----\n");
		printf("id : %d\n", p[i].id);
		printf("name: %s\n", p[i].name);
	}
}

void sort_teacher(struct teacher *tp, int num)
{
	int i = 0;
	int j = 0;
	struct teacher temp_teacher;

	for (i = 0; i < num; i++) {
		for (j = i; j < num; j++) {
			if (tp[i].id > tp[j].id) {
				temp_teacher = tp[i];
				tp[i] = tp[j];
				tp[j] = temp_teacher;
			}
		}
	}
}

void free_teachers(struct teacher **tpp, int num)
{
	struct teacher *tp = *tpp;
	int i = 0;

	if (tpp == NULL) {
		return ;
	}

	if (tp != NULL) {
		for (i = 0; i < num; i++) {
			if (tp[i].name != NULL) {
				free(tp[i].name);
				tp[i].name = NULL;
			}
		}

		free(tp);
		*tpp = NULL;
	}

	return;
}


int main(void)
{
	struct teacher *tp = NULL;
	int num = 2;
	int i = 0;
	int ret = 0;

	ret = create_teachers(&tp, num);
	if (ret < 0) {
		return -1;
	}

	for (i = 0; i < num; i++) {
		printf("enter tp[%d]'s id  ", i);
		scanf("%d", &tp[i].id);
		printf("enter tp[%d]'s name ", i);
		scanf("%s", tp[i].name);
	}

	print_teacher(tp, num);

	sort_teacher(tp, num);
	printf("after sort\n");

	print_teacher(tp, num);

	free_teachers(&tp, num);

	if (tp == NULL) {
		printf("freee succ!\n");
	}


	return 0;
}