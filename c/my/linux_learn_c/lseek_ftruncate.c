#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	int fd;

	fd = open("lseek.txt", O_RDONLY | O_CREAT, 0664);//fd=fileno(fp);
	if(fd < 0){
		perror("open lseek.txt error");
		exit(1);
	}

	int len = lseek(fd, 0, SEEK_END);
	if(len == -1){
		perror("lseek error");
		exit(1);
	}
	printf("len of msg = %d\n", len);

    //int ret = truncate("lseek.txt", 1500);
    int ret = ftruncate(fd, 1800);
	if(ret == -1){
		perror("ftrun error");
		exit(1);
	}

    len = lseek(fd, 999, SEEK_SET);
	if(len == -1){
		perror("lseek seek_set error");
		exit(1);
	}
    ret = write(fd, "a", 1);
	if(ret == -1){
		perror("write error");
		exit(1);
	}


	off_t cur = lseek(fd, -10, SEEK_SET);
	printf("--------| %ld\n", cur);
	if(cur == -1){
		perror("lseek error");
		exit(1);
	}

	close(fd);

	return 0;
}
