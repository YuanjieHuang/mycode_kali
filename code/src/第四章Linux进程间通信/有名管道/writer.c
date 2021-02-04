#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define N 64

int main(int argc, char *argv[])
{
	int pfd, fds, nbyte;
	char buf[N];

	if (argc < 2)
	{
		printf("Usage : %s <src_file>\n", argv[0]);
		return -1;
	}

	if ((fds = open(argv[1], O_RDONLY)) < 0)
	{
		perror("fail to open src file");
		exit(-1);
	}

	if ((pfd = open("myfifo", O_WRONLY)) < 0)
	{
		perror("fail to open fifo");
		exit(-1);
	}

	while ((nbyte = read(fds, buf, N)) > 0)
	{
		write(pfd, buf, nbyte);
	}
	close(fds);
	close(pfd);

	return 0;
}
