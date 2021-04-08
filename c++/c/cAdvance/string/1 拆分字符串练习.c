#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
有一个字符串符合以下特征（“abcdef,acccd,eeee,aaaa,e3eeee,ssss,”）
写两个函数(API)，输出以下结果
第一个API
1)以逗号分隔字符串，形成二维数组，并把结果传出
2)把二维数组行数运算结果也传出
第二个API
1)以逗号分隔字符串，形成一个二级指针。
2)把一共拆分多少行字符串个数传出
要求：
1, 能正确表达功能的要求，定义出接口。
2, 正确实现接口和功能.
3, 编写正确的测试用例.
*/

int spitString(char *str, char ch, char array[][30], int *count)
{
	char *p = str;
	char *q = p;
	int temp_count = 0;
	int len = 0;

	if (str == NULL || array == NULL || count == NULL) {
		fprintf(stderr, "str == NULL || array == NULL || count == NULL\n");
		return -1;
	}

	//在一个字符串中 找到一个字符  找到了 返回第一个字符的地址， 失败返回NULL
	//strchr(母串， 字符)
	while ((p = strchr(p, ch)) != NULL) {
		//找到了
		strncpy(array[temp_count], q, p - q);
		array[temp_count][p - q] = '\0';

		temp_count++;
		p++;
		q = p;
		if (*p == '\0') {
			break;
		}
	}

	if (*q != '\0') {
		len = (str + strlen(str)) - q;
		strncpy(array[temp_count], q, len);
		array[temp_count][len] = '\0';
		temp_count++;
	}

	*count = temp_count;

	return 0;
}

int main(void)
{
	char *str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	char array[10][30];
	int count = 0;
	int retn = 0;
	int i = 0;

	retn = spitString(str, ',', array, &count);
	if (retn < 0) {
		fprintf(stderr, "spitString er\n");
		return -1;
	}


	for (i = 0; i < count; i++) {
		printf("array[%d]:%s\n", i, array[i]);
	}




	return 0;
}