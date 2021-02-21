#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

int main(void)
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