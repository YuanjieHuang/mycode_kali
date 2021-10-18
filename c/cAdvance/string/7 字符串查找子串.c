#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//strstr(母串， 子串)
//统计 子串在母串的个数
int get_sub_str_count(char *src, char *sub_str)
{
	char *p = src;
	int cnt = 0;
	if (src == NULL || sub_str == NULL) {
		fprintf(stderr, "(src == NULL || sub_str == NULL\n");
		return -1;
	}
	while ((p = strstr(p, sub_str)) != NULL)
	{
		//找到了子串
		cnt++;
		p += strlen(sub_str);
		if (*p == '\0') {
			break;
		}
	}
	return cnt;
}
int get_sub_str_count2(char *src, char *sub_str, int *cnt_p)
{
	char *p = src;
	int cnt = 0;
	if (src == NULL || sub_str == NULL) {
		fprintf(stderr, "(src == NULL || sub_str == NULL\n");
		return -1;
	}
	while ((p = strstr(p, sub_str)) != NULL)
	{
		//找到了子串
		cnt++;
		p += strlen(sub_str);
		if (*p == '\0') {
			break;
		}
	}
	*cnt_p = cnt;
	return 0;
}
int main(void)
{
	char *str = "21321321312312itcaste21jdisaodjaitcastu34jsioadjitcastdjsaiodjaitcast123itcast";
	char *sub_str = "itcast";
	int cnt = 0;
	cnt = get_sub_str_count(str, sub_str);
	if (cnt < 0) {
		fprintf(stderr, "get_sub_str_count err\n");
		return -1;
	}
	printf("cnt  = %d\n", cnt);
	cnt = 0;
	if (get_sub_str_count2(str, sub_str, &cnt) < 0) {
		fprintf(stderr, "get_sub_str_count2 err\n");
		return -1;
	}
	printf("cnt  = %d\n", cnt);
	return 0;
}
#if 0
int main(void)
{
	char *str = "21321321312312itcaste21jdisaodjaitcastu34jsioadjitcastdjsaiodjaitcast123itcast";
	char *sub_str = "itcast";
	char *p = str;
	int cnt = 0;
	while (   ( p = strstr(p, sub_str) )  != NULL )
	{
		//找到了子串
		cnt++;
		p += strlen(sub_str);
		if (*p == '\0') {
			break;
		}
	}
	printf("cnt = %d\n", cnt);
	return 0;
}
#endif
#if 0
//查找子串 do-while
int main(void)
{
	char *str = "21321321312312itcaste21jdisaodjaitcastu34jsioadjitcastdjsaiodjaitcast123";
	//                                                 ↑
	char *sub_str = "itcast";
	char *p = NULL;
	int cnt = 0; //统计的个数
	p = str;
	//do -while
	do {
		p = strstr(p, sub_str);
		if (p != NULL) {
			//找到了一个
			cnt++;
			p++;
		}
	} while (p != NULL);
	printf("cnt = %d\n", cnt);
	return 0;
}
#endif