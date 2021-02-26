线程创建-pthread_create     进程间不共享内存，cpu切换消耗大，catch和tlb需要重写
#include <pthread.h>
int pthread_create(pthread_t *thread,const pthread_attr_t *attr, void *(*routine)(void *)), void *arg);
成功返回0，失败返回错误码
thread线程对象
attr线程属性，NULL代表默认属性
routine线程执行的函数
arg传递给routine的参数
线程回收-pthread_join
#include <pthread.h>
int pthread_jion(pthread_t thread, void **retval);
成功返回0，失败返回错误码
thread要回收的线程对象
调用线程阻塞直到thread结束
*retval接收线程thread的返回值
线程结束-pthread_exit
#include <pthread.h>
void pthread_exit(void *retval);
结束当前线程
retval可被其他线程通过pthread_join获取
线程私有资源被释放
线程间通信
    1.全局变量
        信号量（灯），代表某一类资源，其值表示系统中该资源的数量
    Posix信号量
        1，无名信号量（基于内存的信号量）
        2，有名信号量
    pthread库函数：
        信号量初始化-sem_init
    #include <semaphore.h>
        int sem_init(sem_t *sem, int pshared, unsigned int val);
    P/V操作
        int sem_wait(sem_t *sem);      P
        int sem_post(sem_t *sem);      v
无名管道
    特点：
    1.只用于具有亲缘关系的进程之间通信
    2.单工的通信模式，具有固定的读端和写端
    3.无名管道创建时会返回两个文件描述符，分别用于读写管道
创建：
    #include <unistd.h>
    int pipe(int pfg[2]);
    消息队列结构：
    打开/创建：
    #inlude <sys/ip.h>
    #include <sys/msg.h>
    int msgget(key_t key, int msgflg);
    int msgsnd(int msgid, const void *msgp, size_t size, int msgflg);
消息格式：结构体
    tepydef struct
    {
        long mtype;
        char mtext[64];
    }MSG;
msgsnd
msgrcv
int msgrcv(int msgid, void *msgp, size_t size, long msgtype, int msgflg);
msgctl
int msgctl(int msgid, int cmd, struct msqid_ds *buf);
system v IPC-信号灯
类型：
POSIX无名信号灯
有名
SYSTEM V：是信号灯的集合，可同时操作多个信号灯。
计数信号灯
1.打开
<sys/ipc.h><sys/sem.h>
int semget (key_t key, int nsems, int semflg);
2.初始化
int semctl(int semid, int semnum, int cmd, ...);
3.P/V操作
int semop(int semid, struct sembuf *sops, unsigned nsops);
4.删除
