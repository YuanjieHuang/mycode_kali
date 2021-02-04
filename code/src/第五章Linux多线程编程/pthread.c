#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define  N  64

char buf[N];
sem_t sem_r;
sem_t sem_w;

void *thread_function(void *arg);

int main()
{
	pthread_t a_thread;

	sem_init(&sem_r, 0, 0);
	sem_init(&sem_w, 0, 1);
	if (pthread_create(&a_thread, NULL, thread_function, NULL) < 0)
	{
		perror("fail to pthread_create");
		exit(-1);
	}

	while ( 1 )
	{
		sem_wait(&sem_w);
		printf("input : ");
		fgets(buf, N, stdin);
		if (strcmp(buf, "quit\n") == 0) break;
		sem_post(&sem_r);
	}

	return 0;
}

void *thread_function(void *arg)
{
	while ( 1 )
	{
		sem_wait(&sem_r);
		printf("read from buf : %s", buf);
		sem_post(&sem_w);
	}
}
