#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    extern char **environ;
    for (int i = 0; environ[i]; i++)
        printf("%s\n", environ[i]);
    printf("-----------------------\n");
    printf("PATH=%s\n", getenv("PATH"));
    setenv("DOG", "wangwangwang", 1);
    printf("dog=%s\n", getenv("DOG"));
    int ret = unsetenv("DOG");
    if (ret == -1) {
        perror("unsetenv error");
        return 1;
    }
    printf("dog=%s\n", getenv("DOG"));
    return 0;
}

extern char **environ;
char *my_getenv(const char *name)
{
	if(NULL == name)
	{
		strerror("Input is NULL");
	}
	char *p = NULL;
	int i, len;
	for(i = 0; environ[i] != NULL; i++){
		p = strstr(environ[i], "=");
		len = p - environ[i];
		if(strncmp(name, environ[i], len) == 0){
			return p+1;
		}
	}
	return NULL;
}
void my_strstr()
{
   const char haystack[20] = "RUNOOBoooooo";
   const char needle[10] = "NOOB";
   char *ret;
   ret = strstr(haystack, needle);
   printf("子字符串是： %s\n", ret);
}
int test(int argc, char *argv[])
{
	my_strstr();
	char *p = NULL;
	// p = getenv(argv[1]);
	p = my_getenv(argv[1]);
	if (p == NULL)
		printf("there is no match\n");
	else
	{
		if(NULL == p){
			perror("p=NULL\n");
		}
		else
		{
			printf("%s\n", p);
		}
	}
	return 0;
}