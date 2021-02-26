#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define N 64

int main(int argc, char *argv[])
{
	int fds, fdt, nbyte;
	char buf[N];

	if (argc < 3)
	{
		printf("Usage : %s <src_file> <dst_file>\n", argv[0]);
		return -1;
	}

	if ((fds = open(argv[1], O_RDONLY)) < 0)
	{
		perror("fail to open");
		return -1;
	}

	if ((fdt = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0)
	{
		perror("fail to open");
		return -1;
	}

	while ((nbyte = read(fds, buf, N)) > 0)
	{
		write(fdt, buf, nbyte);
	}
	close(fds);
	close(fdt);

	return 0;
}
