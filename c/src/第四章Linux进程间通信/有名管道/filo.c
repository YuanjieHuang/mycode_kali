 #include

#include

#include

#include

#include

#include

#include

#include

#include

#define ERR_EXIT(m)

do {

perror(m);

exit(EXIT_FAILURE);

} while(0)

int main(int argc, char *argv[])

{

mkfifo("tp", 0644);

int infd = open("Makefile", O_RDONLY);

if (infd == -1)

ERR_EXIT("open error");

int outfd;

outfd = open("tp", O_WRONLY);

if (outfd == -1)

ERR_EXIT("open error");

char buf[1024];

int n;

while ((n = read(infd, buf, 1024)) > 0)

write(outfd, buf, n);

close(infd);

close(outfd);

return 0;

}