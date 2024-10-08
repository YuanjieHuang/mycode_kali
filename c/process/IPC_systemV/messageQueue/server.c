#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define N 64

#define TypeA 100
#define TypeB 200
#define SERVER 2

#define LEN (sizeof(MSG) - sizeof(long))

typedef struct
{
	long mtype;
	char mtext[N];
} MSG;

int main()
{
	key_t key;
	int msgid;
	MSG buf, buf1;
	pid_t pid;

	if ((key = ftok(".", 'm')) < 0)
	{
		perror("fail to ftok");
		exit(-1);
	}
	
	if ((msgid = msgget(key, 0666|IPC_CREAT)) < 0)
	{
		perror("fail to msgget");
		exit(-1);
	}
	printf("key:%d msgid:%d\n",key, msgid);
	if ((pid = fork()) < 0)
	{
		perror("fail to fork");
		exit(-1);
	}
	else if (pid == 0)  // recv message
	{
		while ( 1 )
		{
			msgrcv(msgid, &buf, LEN, TypeA, 0);
			if (strncmp(buf.mtext, "quit", 4) == 0) 
			{
				kill(getppid(), SIGUSR1);
				msgctl(msgid, IPC_RMID, NULL);
				exit(0);
			}
			printf("recv from clientA : %s\n", buf.mtext);

			msgrcv(msgid, &buf1, LEN, TypeB, 0);
			if (strncmp(buf.mtext, "quit", 4) == 0) 
			{
				kill(getppid(), SIGUSR1);
				msgctl(msgid, IPC_RMID, NULL);
				exit(0);
			}
			printf("recv from clientB : %s\n", buf.mtext);
		}
	}
	else  // send message
	{
		buf.mtype = TypeA;
		buf1.mtype = TypeB;
		while ( 1 )
		{
			printf("send to clientA clientB: ");
			fgets(buf.mtext, N, stdin);
			memmove(buf1.mtext,buf.mtext,sizeof(buf.mtext));
			msgsnd(msgid, &buf, LEN, 0);
			msgsnd(msgid, &buf1, LEN, 0);
			if (strncmp(buf.mtext, "quit", 4) == 0) 
			{
				kill(pid, SIGUSR1);
				exit(0);
			}
		}
	}

	return 0;
}