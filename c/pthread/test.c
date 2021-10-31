#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
char message[32] = "Hello World";
void thread_func()
{
	// sleep(1);
	printf("tid:%d",pthread_self());
	strcpy(message, "marked by thread");
	pthread_exit("thank you for waiting for me ");
}
int main(void)
{
	pthread_t a_thread = 0;
	void *result;
	if(pthread_create(&a_thread, NULL, thread_func, NULL) !=0 )
	{
		printf("fail to pthread_create");
		exit(-1);
	}
	
	pthread_join(&a_thread, &result);
	printf("result is %s\n", result);
	printf("message is %s\n", message);
	return 0;
}
