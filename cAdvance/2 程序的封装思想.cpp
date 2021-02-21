#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


//数组作为函数参数， 有一个退化的问题
//int printArray(int array[7], int len)
int printArray(int array[], int len) //
//int printArray(int *array, int len)
{
	int i = 0;

	// 7 叫 硬代码
	for (i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	printf("---- 小test ---\n");
	printf("len = %d\n", len);
	int size = sizeof(array) / sizeof(array[0]);//sizeof求一个数据类型的大小
	printf("size = %d\n", size);
	printf("---- 小test ---\n");

	return 0;
}

int sortArray(int array[], int len)
{
	int i = 0; //外层
	int j = 0;//内层
	int temp = 0;

	//当i = 0时候， 让j 从 0 到n 进行遍历， 找到一个最小值
	//当 i =1 时候， 让j从1 到n 进行遍历， 找到一个最小值
	//按住i不放， j 通过内层逐级遍历
	for (i = 0; i < len; i++) {
		for (j = i; j < len; j++) {
			if (array[j] > array[i]) {
				//需要交换
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	return 0;//在C语言 0 函数执行成功  < 0 是错误 >1做一些返回值处理
}

int main(void)
{
	int array[] = { 3, 5, 4, 11, 13, 9, 18 , 123, 143};

	int len = sizeof(array) / sizeof(array[0]);

	printf("排序之前:\n");
	printArray(array, len);

	//进行排序
	sortArray(array, len);

	printf("排序之前:\n");
	printArray(array, len);


	return 0;
}