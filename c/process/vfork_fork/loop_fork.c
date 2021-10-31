#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int n = 5, i;                //默认创建5个子进程
    if (argc == 2) {    
        n = atoi(argv[1]);
    }
    for (i = 0; i < n; i++)    //出口1,父进程专用出口
        if (fork() == 0)
            break;            //出口2,子进程出口,i不自增
    if (n == i) {
        //sleep(n);
        printf("I am parent, pid = %d\n", getpid());
    } else {
        //sleep(i);
        printf("I'm %dth child, pid = %d\n", 
                i+1, getpid());
    }
    return 0;
}
/*
I'm 1th child, pid = 9129
I'm 2th child, pid = 9130
I'm 3th child, pid = 9131
I am parent, pid = 9128
I'm 5th child, pid = 9133
I'm 4th child, pid = 9132
*/