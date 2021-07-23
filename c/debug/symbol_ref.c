#include <stdio.h>
#include <pthread.h>

int pthread_create (pthread_t *__restrict __newthread,
			   const pthread_attr_t *__restrict __attr,
			   void *(*__start_routine) (void *),
			   void *__restrict __arg) __attribute__((weak));
extern int exc;
 int weak; //未初始化的全局变量为弱符号
 int strong =1;

 __attribute__((weak)) weak2 = 2;

 __attribute__((weak)) void foo();
 int main()
 {
    if(foo) foo();
    if(pthread_create)
        printf("This is multi-thread version\n");
    else
        printf("This is single-thread version\n");
    
    return 0;
 }
