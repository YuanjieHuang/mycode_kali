#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 64

struct teacher
{
	int id;
	char *name;
	char **student_name;
	int stu_num;
};

int create_teacher(struct teacher **tpp, int num)
{
	struct teacher *tp = NULL;
	int i = 0;

	if (tpp == NULL) {
		return -1;
	}

	tp = (struct teacher *)malloc(sizeof(struct teacher) * num);
	if (tp == NULL) {
		fprintf(stderr, "malloc struct teacher * tp error\n ");
		return -1;
	}
	memset(tp, 0, sizeof(struct teacher) *num);


	for (i = 0; i < num; i++) {
		tp[i].name = (char*)malloc(sizeof(char)*NAME_LEN);
		memset(tp[i].name, 0, NAME_LEN);
	}

	*tpp = tp;

	return 0;
}

int create_student(struct teacher *tp)
{
	int i = 0;

	if (tp == NULL) {
		return -1;
	}

	tp->student_name = (char **)malloc(sizeof(char*)* (tp->stu_num) );
	if (tp->student_name == NULL) {
		fprintf(stderr, "malloc tp->studentname error\n");
		return -1;
	}
	memset(tp->student_name, 0, sizeof(char *)* tp->stu_num);

	
	for (i = 0; i < tp->stu_num; i++) {
		tp->student_name[i] = (char*)malloc(sizeof(char)*NAME_LEN);
		memset(tp->student_name[i], 0, sizeof(char)*NAME_LEN);
	}

	return 0;
}

void print_teachers(struct teacher *tp, int num)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < num; i++) {
		//代表一个老师
		printf("=====\n");
		printf("id: %d\n", tp[i].id);
		printf("name : %s\n", tp[i].name);
		printf("stu_name:%d\n", tp[i].stu_num);
		for (j = 0; j < tp[i].stu_num; j++) {
			printf("stu[%d]:%s\n", j, tp[i].student_name[j]);
		}
	}
}

void sort_teachers(struct teacher *tp, int num)
{
	int i = 0;
	int j = 0;
	struct teacher temp_teacher;

	if (tp == NULL) {
		return;
	}

	for (i = 0; i < num; i++) {
		for (j = i; j < num; j++) {
			if (tp[i].id > tp[j].id) {
				temp_teacher = tp[i];
				tp[i] = tp[j];
				tp[j] = temp_teacher;
			}
		}
	}

	return ;
}

void free_teachers(struct teacher **tpp, int num)
{
	struct teacher *tp = *tpp;

	int i = 0;
	int j = 0;

	if (tpp == NULL) {
		return;
	}

	if (tp == NULL) {
		return;
	}

	for (i = 0; i < num; i++) {
		//释放一个老师
		// 线是否老师 名字
		if (tp[i].name != NULL) {
			free(tp[i].name);
			tp[i].name = NULL;
		}

		//释放学生信息
		if (tp[i].student_name != NULL) {

			for (j = 0; j < tp[i].stu_num; j++) {
				if (tp[i].student_name[j] != NULL) {
					free(tp[i].student_name[j]);
					tp[i].student_name[j] = NULL;
				}
			}

			free(tp[i].student_name);
			tp[i].student_name = NULL;
		}
	}

	free(tp);

	*tpp = NULL;
}

int main(void)
{
	int num = 2;
	int i = 0;
	int j = 0;
	struct teacher *tp = NULL;

	//开辟num个teacher空间
	create_teacher(&tp, num);

	for (i = 0; i < num; i++) {
		//代表一个老师
		printf("enter tp[%d]'s id: ", i);
		scanf("%d", &tp[i].id);
		printf("enter tp[%d]'s name:", i);
		scanf("%s", tp[i].name);
		printf("enter tp[%d]'s stu_num", i);
		scanf("%d", &(tp[i].stu_num)  );
		create_student(&tp[i]);
		for (j = 0; j < tp[i].stu_num; j++) {
			printf("enter tp[%d]->std[%d]'name: ", i, j);
			scanf("%s", tp[i].student_name[j]);
		}
	}

	print_teachers(tp, num);

	sort_teachers(tp, num);

	printf(" after sort\n");

	print_teachers(tp, num);

	free_teachers(&tp, num);

	if (tp == NULL) {
		printf("tp == NULL\n");
	}

	return 0;
}