#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void free_mem(char ***array_p, int count)
{
	char **array = *array_p;
	int i = 0;

	if (array_p == NULL) {
		return;
	}

	void free(void*);

	if (array != NULL) {
		for (i = 0; i < count; i++) {
			if (array[i] != NULL) {
				free(array[i]);
				array[i] = NULL;
			}
		}

		free(array);
		*array_p = NULL;
	}
}


int spitString(char *str, char ch, char ***array_p, int *count)
{
	char * p = str;
	char * q = p;
	int temp_count = 0;
	char **array = NULL;
	int str_len = 0;
	int retn = 0;


	if (str == NULL || array_p == NULL || count == NULL) {
		fprintf(stderr, " (str == NULL || array_p == NULL || count == NULL)\n");
		return -1;
	}

	//1 求出 字符串中 拆分的个数
	while ((p = strchr(p, ch)) != NULL) {
		temp_count++;
		p++;
		q = p;
		if (*q == '\0') {
			break;
		}
	}
	if (*q != '\0') {
		temp_count++;
	}
	//此时temp_count 就是 子字符串的个数


	//2 根据个数开辟指针数组 在堆上
	array = (char**)malloc(sizeof(char*)* temp_count);
	if (array == NULL) {
		fprintf(stderr, "malloc  char **array error\n");
		retn = -1;
		goto END;
	}
	memset(array, 0, sizeof(char*)*temp_count);

	//3 拆分字符串， 为每一个指针开辟堆空间 拷贝字符串
	p = str;
	q = p;
	temp_count = 0;

	while ((p = strchr(p, ch)) != NULL) {
		//找到了
		str_len = p - q;
		array[temp_count] = (char*)malloc(sizeof(char)* (str_len+1));
		if (array[temp_count] == NULL) {
			fprintf(stderr, "malloc array[%d] error\n", temp_count);
			retn = -1;
			goto END;
		}
		strncpy(array[temp_count], q, str_len);
		array[temp_count][str_len] = '\0';

		temp_count++;
		p++;
		q = p;
		if (*p == '\0') {
			break;
		}
	}

	if (*q != '\0') {
		str_len = (str + strlen(str)) - q;
		array[temp_count] = (char*)malloc(sizeof(char)*(str_len + 1));
		if (array[temp_count] == NULL) {
			fprintf(stderr, "malloc array[%d] error\n", temp_count);
			retn = -1;
			goto END;
		}

		strncpy(array[temp_count], q, str_len);
		array[temp_count][str_len] = '\0';

		temp_count++;
	}

	if (array != NULL) {
		*array_p = array;
		*count = temp_count;
	}

	//释放内存的步骤
END:
	if (retn != 0) {
		//已经出现错误了
		free_mem(&array, temp_count);
	}
	return 0;
}


int main(void)
{
	char *str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	char **array = NULL;
	int count = 0;
	int retn = 0;
	int i = 0;

	retn = spitString(str, ',', &array, &count);

	for (i = 0; i < count; i++) {
		printf("array[%d]: %s\n", i, array[i]);
	}

	free_mem(&array, count);

	if (array == NULL) {
		printf("array kong\n");
	}


	return 0;
}