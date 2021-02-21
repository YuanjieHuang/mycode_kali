#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int get_mem(char ***array_p, int num)
{
	char **array = NULL;
	int i = 0;

	array = (char**)malloc(sizeof(char*)* num);//在堆上开辟num个 char*指针
	if (array == NULL) {
		fprintf(stderr, "malloc char **array error\n");
		return -1;
	}
	memset(array, 0, sizeof(char*)*num);

	for (i = 0; i < num; i++) {
		array[i] = (char*)malloc(64);
		if (array[i] == NULL) {
			fprintf(stderr, "maloc array[%d] error\n", i);
			return -1;
		}
		memset(array[i], 0, 64);

		//赋值
		sprintf(array[i], "%d%d%d%d", 9 - i, 9 - i, 9 - i, 9 - i);
	}

	*array_p = array;

	return 0;
}

void free_mem(char ***array_p, int num)
{
	int i = 0;

	if (array_p == NULL) {
		return;
	}
	char **array = *array_p;


	for (i = 0; i < num; i++) {
		if (array[i] != NULL) {
			free(array[i]);
			array[i] = NULL;
		}
	}

	free(array);

	*array_p = NULL;
}

int main(void)
{
	char **my_array = NULL;
	int num = 4;

	get_mem(&my_array, num);
	printf("-----\n");
	free_mem(&my_array, num);

	if (my_array == NULL) {
		printf("kong\n");
	}



	return 0;
}