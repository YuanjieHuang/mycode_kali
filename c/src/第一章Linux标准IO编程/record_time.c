#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define N 64

int main(int argc, char *argv[])
{
	FILE *fp;
	time_t t;
	struct tm *tp;
	char buf[N];
	int line = 0;

	if (argc < 2)
	{
		printf("Usage : %s <file>\n", argv[0]);
		return -1;
	}

	if ((fp = fopen(argv[1], "a+")) == NULL)
	{
		perror("fail to fopen");
		return -1;
	}

	while (fgets(buf, N, fp) != NULL)
	{
		if (buf[strlen(buf)-1] == '\n') line++;
	}

	while ( 1 )
	{
		time(&t);
		tp = localtime(&t);
		fprintf(fp, "%d, %d-%d-%d %d:%d:%d\n", ++line, tp->tm_year+1900, tp->tm_mon+1,
											   tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec);
		fflush(fp);
		sleep(1);
	}

	return 0;
}
