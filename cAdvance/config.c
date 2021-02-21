#include "config.h"


int write_config(IN const char *file_name, IN const char *key, IN const char *value, IN const int value_len)
{
	//key = value
	FILE *fp = NULL;
	char file_buf[FILE_MAX_LEN] = { 0 }; //存放文件中所有的数据
	char line_buf[LINE_MAX_LEN] = { 0 };  //存放文件每行的数据
	int pos_begin = 0;
	int pos_end = 0;
	int key_exist = 0; //key 是否已经存在 0 代表不存在 1 代表存在


	//假设这个文件存在
	fp = fopen(file_name, "r+");
	if (fp == NULL) {
		//1 可能是文件不存在
		fp = fopen(file_name, "w+");
		if (fp == NULL) {
			fprintf(stderr, "fopen %s error\n", file_name);
			return -1;
		}
	}

	//将文件内部的指针 一到头部
	fseek(fp, 0, SEEK_SET);
	pos_begin = ftell(fp);

	//将文件内部指针 移到 尾部
	fseek(fp, 0, SEEK_END);
	pos_end = ftell(fp);

	fseek(fp, 0, SEEK_SET);

	if ((pos_end - pos_begin) > FILE_MAX_LEN) {
		fprintf(stderr, "文件太大\n");
		fclose(fp);
		return -1;
	}

	//文件合法
	while (!feof(fp)) {
		//文件没有读完
		memset(line_buf, 0, LINE_MAX_LEN);
		if (fgets(line_buf, LINE_MAX_LEN, fp) == NULL) {
			break;
		}
		//把一行数据读到line_buf中了
		printf("line_buf =%s\n", line_buf);
		//判断一行数据中是否有key,如果有的话 修改key的value值
		if (strstr(line_buf, key) != NULL) {
			//key 在文件中已经存在 需要修改key的value
			memset(line_buf, 0, LINE_MAX_LEN);
			sprintf(line_buf, "%s = %s\n", key, value);
			key_exist = 1;
		}
		//key1 = value1

		//name = li4\nid = 10\nkey1 = value1\0  file_buf  -->config.ini
		strcat(file_buf, line_buf);
	}

	if (key_exist == 0) {
		fprintf(fp, "%s = %s\n", key, value);
	}
	else {
		if (fp != NULL) {
			fclose(fp);
			fp = NULL;
		}

		fp = fopen(file_name, "w+");
		if (fp == NULL) {
			fprintf(stderr, "open error\n");
			return -1;
		}
		printf("file_buf:%s\n", file_buf);
		fputs(file_buf, fp);
	}


	if (fp != NULL) {
		fclose(fp);
		fp = NULL;
	}

	return 0;
}

int read_config(IN const char *file_name, IN const char *key, OUT char *value, OUT int *value_len)
{
	char line_buf[LINE_MAX_LEN] = { 0 };
	int ret = 0;
	FILE *fp = NULL;
	int temp_value_len = 0;
	int key_exist = 0;

	fp = fopen(file_name, "r");
	if (fp == NULL) {
		fprintf(stderr, "fopen %s error\n", file_name);
		return -1;
	}

	while (!feof(fp)) {
		memset(line_buf, 0, LINE_MAX_LEN);
		if (fgets(line_buf, LINE_MAX_LEN, fp) == NULL) {
			break;
		}

		ret = getKeyByValue(line_buf, key, value, &temp_value_len);
		if (ret < 0) {
			continue;
		}
		else {
			key_exist = 1;
			break;
		}
	}

	if (key_exist == 0) {
		printf("%s 不存在\n", key);
	}
	else {
		*value_len = temp_value_len;
	}

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}




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
int getKeyByValue(char *keyvaluebuf, const char *keybuf, char *valuebuf, int *valuebuflen)
{
	char *p = keyvaluebuf; //原字符串
	char *key_p = (char*)keybuf; //key : "key1"
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
		//fprintf(stderr, "未找到 key %s", key_p);
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
