#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


/*
有一个字符串开头或结尾含有n个空格
（” abcdefgdddd ”），
欲去掉前后空格，返回一个新字符串。
要求1：请自己定义一个接口（函数），并实现功
能；
要求2：编写测试用例。
int trimSpace(char *inbuf, char *outbuf);
*/
int trimSpace(char *inbuf, char *outbuf)
{
	int i = 0;
	int j = 0;
	int len = 0;

	if (inbuf == NULL || outbuf == NULL) {
		fprintf(stderr, " (inbuf == NULL || outbuf == NULL)\n  ");
		return -1;
	}

	j = strlen(inbuf) - 1;

	//左边开始遍历
	while (isspace(inbuf[i]) && inbuf[i] != '\0') {
		i++;
	}

	//右边
	while (isspace(inbuf[j]) && j > i) {
		j--;
	}

	len = j - i + 1;

	strncpy(outbuf, inbuf + i, len);
	outbuf[len] = '\0';

	return 0;
}


/*
2、键值对（“key = value”）字符串，在开发中经常使用.
要求1：请自己定义一个接口，实现根据key获取.
要求2：编写测试用例。
要求3：键值对中间可能有n多空格，请去除空格
注意：键值对字符串格式可能如下：
"key1	=	value1"
"key2	=							value2"
"key3		=	hello word      "
"key4								=	value4"
"key5			=			"
"key6			="
int	getKeyByValue(char	*keyvaluebuf,		char	*keybuf,		char	*valuebuf,	int	*
valuebuflen);
int	main(void)
{
//...
getKeyByValude("key1	=	valude1",	"key1",	buf,	&len);
//...
return 0;
}
*/


/*
  此函数功能 解析 类似以下字符串
  "key1	=	value1"
  " key2   	=							value2            "
  //             ↑
  "key3		=	hello word      "
  "key4								=	value4"
  "key5			=			"
  "key6			="
  通过key值 找到value

  keyvaluebuf  in  : 传入原字符串
  keybuf          in  : 要找到的key值
  valuebuf      out: 得到value值
  valuebuflen  out: 得到的value长度


  return   0 成功 -1 失败

*/
int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int *valuebuflen)
{
	char *p = keyvaluebuf; //原字符串
	char *key_p = keybuf; //key : "key1"
	char *value_p = valuebuf;// 得到的 目的内存首地址
	int ret = 0;
	int len = 0;

	if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL) {
		fprintf(stderr, "[%s:%d]keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL\n",
			__FUNCTION__, __LINE__);
		return -1;
	}

	//查找keyvaluebuf 是否有 keybuf  
	p = strstr(p, key_p);
	if (p == NULL) {
		//没找到 key 值
		fprintf(stderr, "未找到 key%s", key_p);
		return -1;
	}
	p += strlen(key_p);

	//查找keyvaluebuf 是否有 =
	p = strstr(p, "=");
	if (p == NULL) {
		//没找到=
		fprintf(stderr, "未找到=\n");
		return -1;
	}
	p += strlen("=");

	//找到=号右边的value 去掉value两端的空白字符
	ret = trimSpace(p, value_p);
	if (ret < 0) {
		fprintf(stderr, "trimSpace err\n");
		return -1;
	}

	len = strlen(value_p);
	*valuebuflen = len;

	return 0;
}


int main(void)
{
	char *str = " key2   	=";
	int retn = 0;
	char value[64] = { 0 };
	int value_len = 0;
	char *key = "key2";

	retn = getKeyByValue(str, key, value, &value_len);
	if (retn < 0) {
		fprintf(stderr, "getKeyByValue err\n");
		return -1;
	}

	printf("key:%s  --> value:%s[%d]\n", key, value, value_len);


	return 0;
}