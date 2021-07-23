#include <stdio.h>  
#include <stdlib.h>  
int main(void)  
{  
 int *p;  
 int i;  
#ifdef DEBUG  
 setenv("MALLOC_TRACE", "./memleak.log", 1);  
 mtrace();  
#endif  
 p=(int *)malloc(1000);  
 return 0;  
}

// 2、编译gcc -g -DDEBUG -o test1 test1.c
// 3、执行./test1，在目录里会发现./memleak.log。
// 4、使用mtrace <your_proc> memleak.log 查看信息。