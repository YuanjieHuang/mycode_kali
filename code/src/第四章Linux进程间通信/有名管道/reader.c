#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define N 64

int main(int argc, char *argv[])
{
	int pfd, fdt, nbyte;
	char buf[N];

	if (argc < 2)
	{
		printf("Usage : %s <dst_file>\n", argv[0]);
		return -1;
	}

	if ((fdt = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0)
	{
		perror("fail to open dst file");
		exit(-1);
	}

	if ((pfd = open("myfifo", O_RDONLY)) < 0)
	{
		perror("fail to open fifo");
		exit(-1);
	}

	while ((nbyte = read(pfd, buf, N)) > 0)
	{
		write(fdt, buf, nbyte);
	}
	close(fdt);
	close(pfd);

	return 0;
}
