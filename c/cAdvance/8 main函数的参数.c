#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[], char **env)
{
	int i = 0;

	printf(" ------- argv -------\n");
	for (i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
	printf(" ------- ---- -------\n");

	printf(" ------ evn ------\n");

	for (i = 0; env[i] != NULL; i++) {
		printf("evn[%d]: %s\n",i,  env[i]);
	}
	printf(" ------- ---- -------\n");


	return 0;
}