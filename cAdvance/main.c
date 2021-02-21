
#include "config.h"

#define FILE_NAME "c:/test/config.ini"

void menu()
{
	printf(" ======\n");
	printf("1 写配置\n");
	printf("2 读配置\n");
	printf("0 退出\n");
	printf(" ======\n");

}

int test_write_config(const char *file_name)
{
	//key = value 
	char key[KEY_LEN] = { 0 };
	char value[VALUE_LEN] = { 0 };
	int ret = 0;

	printf("请输入key:");
	scanf("%s", key);
	printf("请输入value:");
	scanf("%s", value);

	ret = write_config(file_name, key, value, strlen(value));
	if (ret < 0) {
		fprintf(stderr, "write_config %s = %s error\n", key, value);
		return -1;
	}

	printf("write %s = %s succ!\n", key, value);

	return 0;
}

int test_read_config(const char *file_name)
{
	char key[KEY_LEN] = { 0 };
	char value[VALUE_LEN] = { 0 };
	int value_len = 0;
	int ret = 0;

	printf("请输入key:");
	scanf("%s", &key);

	ret = read_config(file_name, key, value, &value_len);
	if (ret < 0) {
		fprintf(stderr, "read %s error\n", key);
		return -1;
	}

	printf("read succ: %s = %s, len = %d\n", key, value, value_len);

	return 0;
}


int main(void)
{
	int choice = 0;

	while (1) {
		menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			//写配置文件
			test_write_config(FILE_NAME);
			break;
		case 2:
			//读配置文件
			test_read_config(FILE_NAME);
			break;
		case 0:
			return 0;
		default:
			printf("请输入 0-2\n");
			break;
		}
	}





	return 0;
}