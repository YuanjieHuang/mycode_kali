#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//在堆中 开辟两块内存， 供main函数使用

#define OUT
#define IN

/*
需要外部释放 内存  pp1 和 pp2
*/
/*
   函数的简介： 开辟两块内存

   pp1  out  开辟一个堆内存 
   pp2  out  

   len_p_1 out 第一块内存有效数据的大小
   len_p_2 out 
   len1     in   需要开辟1 内存的大小
   len2     in   需要开辟2 内存的大小

   return -1 失败
             0  成功
*/
int get_mem(OUT char **pp1, OUT char **pp2, OUT  int *len_p_1, OUT int *len_p_2, IN  int len1, IN int len2)//接口，API
{
	char *p1 = NULL;
	char *p2 = NULL;
	int temp_len1 = 0;
	int temp_len2 = 0;


	p1 = (char*)malloc(len1);//p1
	if (p1 == NULL) {
		fprintf(stderr, "malloc p1 err\n");
		return -1;
	}
	memset(p1, 0, len1);


	p2 = malloc(len2);
	if (p2 == NULL) {
		fprintf(stderr, "malloc p2 err\n");
		return -1;
	}
	memset(p2, 0, len2);

	
	strcpy(p1, "1234567890");
	temp_len1 = strlen(p1);

	strcpy(p2, "abcdefghijk");
	temp_len2 = strlen(p2);
	


	//到此  以上说明程序没问题了
	*pp1 = p1;
	*pp2 = p2;
	*len_p_1 = temp_len1;
	*len_p_2 = temp_len2;  //间接操作


	return 0;
}

//对外提供一个 释放内存的接口
void free_mem(char *p1, char *p2)
{
	if (p1 != NULL) {
		free(p1);
		//p1 = NULL;
	}
	if (p2 != NULL) {
		free(p2);
	}
}

void free_mem2(char **pp1, char **pp2)
{
	char *p1 = NULL;
	char *p2 = NULL;

	p1 = *pp1;
	p2 = *pp2;

	if (p1 != NULL) {
		free(p1);
	}
	if (p2 != NULL) {
		free(p2);
	}

	*pp1 = NULL;
	*pp2 = NULL;

}

int main(void)
{
	char *p1 = NULL;  //第一块内存的首地址
	char *p2 = NULL;

	int len1 = 0; //第一块内存的长度
	int len2 = 0;

	int ret = 0;

	ret = get_mem(&p1, &p2, &len1, &len2, 200, 300);
	if (ret != 0) {
		fprintf(stderr, "get mem error: %d\n", ret);
		return -1;
	}


	//对内存的操作
	printf("p1 : %s[%d], p2 : %s[%d]\n", p1, len1, p2, len2);



	//if (p1 != NULL) {
	//	free(p1);
	//	p1 = NULL;
	//}

	//if (p2 != NULL) {
	//	free(p2);
	//	p2 = NULL;
	//}
	//free_mem(p1, p2);
	//p1 = NULL;
	//p2 = NULL;
	free_mem2(&p1, &p2);

	return 0;
}