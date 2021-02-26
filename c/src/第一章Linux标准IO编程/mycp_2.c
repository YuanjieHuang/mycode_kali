#include <stdio.h>
#include <string.h>
#include <errno.h>

#define N 64

int main(int argc, char *argv[])
{
	FILE *fps, *fpd;
	char buf[N];

	if (argc < 3)
	{
		printf("Usage : %s <src_file> <dst_file>\n", argv[0]);
		return -1;
	}

	if ((fps = fopen(argv[1], "r")) == NULL)
	{
		printf("fail to open %s : %s\n", argv[1], strerror(errno));
		return -1;
	}

	if ((fpd = fopen(argv[2], "w")) == NULL)
	{
		printf("fail to open %s : %s\n", argv[2], strerror(errno));
		return -1;
	}

	while (fgets(buf, N, fps) != NULL)
	{
		fputs(buf, fpd);
	}

	fclose(fps);
	fclose(fpd);

	return 0;
}
