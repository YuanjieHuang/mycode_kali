#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
int main(void)
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