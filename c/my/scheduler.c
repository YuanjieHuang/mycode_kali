#include <sched.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int sched_setscheduler(pid_t pid, int policy, const struct sched_para *para);
int sched_getscheduler(pid_t pid);

int nice(int inc)
int setpriority(int which, int who, int prio)
int getpriority(int which, int who)

int sched_set_priority_max(int policy)
int sched_get_priority_min(int policy)

int chown(const char * pathname, __uid_t owner, __gid_t group)
int fchown(int fd, __uid_t owner, __gid_t group)
int chmod(char *pathname, __mode_t mode)
int fchmod(int fd, __mode_t mode)
int rename()
int ftruncat(int fd, size_t len)
dup dup2 stat fstat lstat fsync flock fcntl select

mkdir()  rmdir()  