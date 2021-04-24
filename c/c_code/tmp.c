#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
int fd;
extern int errno;
int i;
for(i=0;i<20;i++);
{
printf("errno=%d\n",errno);
char * mesg = strerror(errno);
printf("Mesg:%s\n",mesg);
}

}
