#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
void mmap_test()
{
    int fd;
    void *start;
    struct stat sb;
    fd = open("/etc/passwd", O_RDONLY); /*打开/etc/passwd */
    fstat(fd, &sb); /* 取得文件大小 */
    start = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if(start == MAP_FAILED) /* 判断是否映射成功 */
        return;
    printf("%s", start); 
    munmap(start, sb.st_size); /* 解除映射 */
    close(fd);
}
int main(void)
{
    mmap_test();
    char *memp;
    int fd = open("/dev/zero", O_RDWR);
    memp = mmap(NULL, 40, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (memp == MAP_FAILED) {
        perror("mmap err");
        exit(1);
    }
    close(fd);

    pid_t pid = fork();
    if (pid > 0) {
        strcpy(memp, "mmap func create shared mem");
    } else if (pid == 0) {
        printf("%s\n", memp);
    }
    int ret = munmap(memp, 4);
    if (ret == -1) {
        perror("munmap err");
        exit(1);
    }
    return 0;
}
