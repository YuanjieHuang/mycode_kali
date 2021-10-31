#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
void my_fseek()
{
	FILE * stream;
  long offset;
  fpos_t pos;
  stream = fopen("/etc/passwd", "r");
  fseek(stream, 5, SEEK_SET);
  printf("offset = %d\n", ftell(stream));
  rewind(stream);
  fgetpos(stream, &pos);
  printf("offset = %d\n", pos);
  pos.__pos = 10;
  fsetpos(stream, &pos);
  printf("offset = %d\n", ftell(stream));
  fclose(stream);
}
void getFileLen()
{
	int fd=open("test.txt",O_RDWR);
    if(fd == -1)
    {
        perror("open test.txt");
        exit(-1);
    }
    printf("file len:%d \n\n",lseek(fd,0,SEEK_END));
    close(fd);
}
int main(void)
{
	getFileLen();
	int fd, n;
	char msg[] = "It's a test for lseek\n";
	char ch;
	fd = open("lseek.txt", O_RDWR|O_CREAT|O_TRUNC, 0644);
	if(fd < 0){
		perror("open lseek.txt error");
		exit(1);
	}
	printf("lseek return value:%d\n",lseek(fd, 100, SEEK_SET));
    int ret = lseek(fd, 0, SEEK_SET);
	printf("sizeof(msg)=%d ret:%d\n",sizeof(msg),ret);
    if (ret == -1) {
        perror("lseek error");
        exit(1);
    }
	write(fd,msg,sizeof(msg));
	write(fd, "\0", 1);
	int len = lseek(fd, 0, SEEK_END);
    printf("file len = %d\n", len);
	close(fd);
	return 0;
}
