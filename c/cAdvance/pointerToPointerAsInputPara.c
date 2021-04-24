#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*-------------------------*/

//int print_array(char*  array[], int len)
int print_array(char*  *array, int len)
{
	int i = 0;
	for (i = 0; i < len; i++) {
		//printf("%s\n", array[i]);
		printf("%s\n", *(array + i));
	}
	return 0;
}

int sort_array(char *array[], int len)
{
	int i = 0;
	int j = 0;
	char *temp = NULL;

	for (i = 0; i < len; i++) {
		for (j = i; j < len; j++) {
			if (strcmp(array[i], array[j])  > 0) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	return 0;
}

int t_2levelPointerAsInputPara0(void)
{
	char	* myArray[] = { "aaaaaa", "ccccc", "bbbbbb", "111111" };
	int len = 0;


	len = sizeof(myArray) / sizeof(myArray[0]);  // 16 / 4 = 4个

	printf("排序之前\n");
	print_array(myArray, len);

	//排序
	sort_array(myArray, len);

	printf("排序之后\n");
	print_array(myArray, len);

	

	return 0;
}

/*two level poiter*/
//int print_array(char *  *array, int num)
//int print_array(char array[5][6],  int num)
//int print_array(char[6]* array, int num)
int print_array(char array[][6], int num)      //int print_array(char (*array)[6], int num)
{
	int i = 0;

	for (i = 0; i < num; i++) {
		//printf("%s\n", array[i]); //my_array[0]; my_array[0]--->"aaa"  printf(%s, myArray[0]);
		printf("%s\n", *(array + i)); /// ===>array 应该是一个指向 char[6]的指针
	}

	return 0;
}


int sort_array(char array[][6], int num)
{
	char buf[6] = { 0 };
	int i = 0;
	int j = 0;

	for (i = 0; i < num; i++) {
		for (j = i; j< num; j++) {
			if (strcmp(array[i], array[j]) > 0) {
				strcpy(buf, array[i]);
				strcpy(array[i], array[j]);
				strcpy(array[j], buf);
			}
		}
	}

	return 0;
}

int t_2levelPointerAsInputPara1(void)
{
	char my_array[5][6] = { "aaa", "ccc", "bbb", "111" };
	int num = 0;
	int i = 0;


	for (i = 0; i < 5; i++) {
		if (strlen(my_array[i]) != 0) {
			num++;
		}
	}
	printf("num : %d\n", num);

	printf("排序之前\n");
	print_array(my_array, num);

	sort_array(my_array, num);


	printf("排序之后\n");
	print_array(my_array, num);




	return 0;
}


/*-----------------------------------------------*/
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

int t_2levelPointerAsInputPara(void)
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
/*Three level poiter*/
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