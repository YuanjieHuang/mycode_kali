/*  reference https://ixyzero.com/blog/archives/3545.html   */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#if 1
// 获取、设置文件状态标记样例：
#define ERR_EXIT(m) \
    do { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)
void set_flag(int, int);
void clr_flag(int, int);
int main(int argc, char *argv[])
{
    char buf[1024] = {0};
    int ret;
    // int flags;
    // flags = fcntl(0, F_GETFL, 0);
    // if (flags == -1)
    //     ERR_EXIT("fcntl get flag error");
    // printf("flags = %d\n", flags);
    // ret = fcntl(0, F_GETFL, flags | O_NONBLOCK); //设置为非阻塞,但不更改其他状态
    // if (ret == -1)
    //     ERR_EXIT("fcntl set flag error");
    // printf("flags = %d\n", flags);
    errno = 0;
    set_flag(0, O_NONBLOCK);
    ret = read(0, buf, 1024);
    if (ret == -1) {
        printf("errno = %d (%s)\n", errno, strerror(errno));
        ERR_EXIT("read error");
    }
    printf("buf=%s\n", buf);
    return 0;
}
void set_flag(int fd, int flags)
{
    int val;
    val = fcntl(fd, F_GETFL, 0);
    if (val == -1) {
        ERR_EXIT("fcntl get flag error");
    }
    val |= flags;
    if (fcntl(fd, F_SETFL, val) < 0) {
        ERR_EXIT("fcntl set flag error");
    }
}
void clr_flag(int fd, int flags)
{
    int val;
    val = fcntl(fd, F_GETFL, 0);
    if (val == -1)
        ERR_EXIT("fcntl get flag error");
    val &= ~flags;
    if (fcntl(fd, F_SETFL, val) < 0)
        ERR_EXIT("fcntl set flag error");
}
// 将socket fd设置为非阻塞模式：
static int make_socket_non_blocking (int sfd)
{
  int flags, s;
  flags = fcntl (sfd, F_GETFL, 0);
  if (flags == -1) {
      perror ("fcntl");
      return -1;
  }
  flags |= O_NONBLOCK;
  s = fcntl (sfd, F_SETFL, flags);
  if (s == -1) {
      perror ("fcntl");
      return -1;
  }
  return 0;
}
#else
// 获取、设置文件锁样例：
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define ERR_EXIT(m) \
    do { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)
int main(int argc, char *argv[])
{
    int fd;
    fd = open("test2.txt", O_CREAT | O_RDWR | O_TRUNC, 0664);
    if (fd == -1)
        ERR_EXIT("open error");
    /* 只有对文件有相应的读写权限才能施加对应的文件锁 */
    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_WRLCK; // 排他锁,即不允许其他进程再对其加任何类型的锁，但读锁（共享锁）允许
    lock.l_whence = SEEK_SET;
    lock.l_start = 0; //从文件开头开始锁定
    lock.l_len = 0; // 文件全部内容锁住
    if (fcntl(fd, F_SETLK, &lock) == 0)
    {
        /* 若为F_SETLKW,这时如果锁已经被其他进程占用，则此进程会阻塞直到其他进程释放锁*/
        printf("lock success\n");
        printf("press any key to unlock\n");
        getchar();
        lock.l_type = F_UNLCK;
        if (fcntl(fd, F_SETLK, &lock) == 0)
            printf("unlock success\n");
        else
            ERR_EXIT("unlock fail");
    }
    else
        ERR_EXIT("lock fail");
    return 0; //进程退出会对所有文件解锁
}
#endif