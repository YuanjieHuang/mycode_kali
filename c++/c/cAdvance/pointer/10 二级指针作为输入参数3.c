#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char ** get_mem(int num)
{
	char **array = NULL;
	int i = 0;

	array = (char**)malloc(sizeof(char*)* num);//在堆上开辟num个 char*指针
	if (array == NULL) {
		fprintf(stderr, "malloc char **array error\n");
		return NULL;
	}
	memset(array, 0, sizeof(char*)*num);

	for (i = 0; i < num; i++) {
		array[i] = (char*)malloc(64);
		if (array[i] == NULL) {
			fprintf(stderr, "maloc array[%d] error\n", i);
			return NULL;
		}

		//赋值
		sprintf(array[i], "%d%d%d%d", 9-i, 9-i, 9-i, 9-i);
	}

	return array;
} //main::my_array = array;


void free_mem(char **array, int num)
{
	char **temp_array = array;
	int i = 0;

	if (array == NULL) {
		return;
	}

	for (i = 0; i < num; i++) {
		if (temp_array[i] != NULL) {
			free(temp_array[i]);
			temp_array[i] = NULL;
		}
	}

	free(temp_array);
}

int print_array(char **array, int num)
{
	int i = 0; 

	for (i = 0; i < num; i++) {
		printf("%s\n", *(array + i));
		//printf("%s\n", array[i]);
	}

	return 0;
}

int sort_array(char **array, int num)
{
	int i = 0;
	int j = 0;
	char* temp = NULL;

	for (i = 0; i < num; i++) {
		for (j = i; j < num; j++) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	return 0;
}

int main(void)
{
	char **my_array = NULL;

	//通过堆开辟一个 字符串数组
	int num = 4;

	my_array = get_mem(num);
	if (my_array == NULL) {
		fprintf(stderr, "get_mem err\n");
		return -1;
	}
	print_array(my_array, num);

	printf("------\n");
	sort_array(my_array, num);

	print_array(my_array, num);

	free_mem(my_array, num);
	my_array = NULL;


	return 0;
}