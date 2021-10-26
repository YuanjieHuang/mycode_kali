#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define N 64

typedef struct 
{
	pid_t pid;
	char buf[N];
} SHM;

void handler(int signo)
{
	printf("get signal\n");
	return;
}

int main()
{
	key_t key;
	int shmid;
	SHM *p;
	pid_t pid;

	if ((key = ftok(".", 'm')) < 0)
	{
		perror("fail to ftok");
		exit(-1);
	}

	signal(SIGUSR1, handler);
	if ((shmid = shmget(key, sizeof(SHM), 0666|IPC_CREAT|IPC_EXCL)) < 0)
	{
		if (EEXIST == errno)
		{
			printf("%d",errno);
			shmid = shmget(key, sizeof(SHM), 0666);
			p = (SHM *)shmat(shmid, NULL, 0);
			pid = p->pid;
			p->pid = getpid();
			kill(pid, SIGUSR1);
		}
		else
		{
			perror("fail to shmget");
			exit(-1);
		}
	}
	else 
	{
		p = (SHM *)shmat(shmid, NULL, 0);
		p->pid = getpid();
		pause();
		pid = p->pid;
	}

	while ( 1 )
	{
		printf("pid%d write to shm : ",pid);
		fgets(p->buf, N, stdin);
		kill(pid, SIGUSR1);
		if (strcmp(p->buf, "quit\n") == 0) break;
		pause();
	}
	shmdt(p);
	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}
