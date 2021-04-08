#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
char message[32] = "Hello World";
void *thread_func(void *arg);

int main(void)
{
	pthread_t a_thread;
	void *result;
	if(pthread_create(&a_thread, NULL, thread_func, NULL) !=0)
		{
			printf("fail to pthread_create";
			exit(-1);
		}
	
	pthread_join(&a_thread, &result);
	printf("result is %s\n", result);
	printf("message is %s\n", message);
	return 0;
}


void thread_func(void *arg)
{
	sleep(1);
	strcpy(message, "marked by thread");
	pthread_exit("thank you for waiting for me ");
}

编译：gcc -o test test.c -lpthread