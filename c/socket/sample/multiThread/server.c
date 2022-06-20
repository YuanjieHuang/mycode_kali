#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>

#define N 64

typedef struct sockaddr SA;

void handler(int signo)
{
	waitpid(-1, NULL, WNOHANG);

	return;
}

int main(int argc, char *argv[])
{
	int listenfd, connfd;
	char buf[N];
	struct sockaddr_in myaddr;
	pid_t pid;

	if (argc < 3)
	{
		printf("Usage : %s <serv_ip> <serv_port>\n", argv[0]);
		exit(-1);
	}

	// XXX int socket(int domain, int type, int protocol);
	if ((listenfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("fail to socket");
		exit(-1);
	}

	bzero(&myaddr, sizeof(myaddr));
	myaddr.sin_family = PF_INET;
	myaddr.sin_port = htons(atoi(argv[2]));
	myaddr.sin_addr.s_addr = inet_addr(argv[1]);
	int reuse = 1;
	setsockopt(listenfd,SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
	if (bind(listenfd, (SA *)&myaddr, sizeof(myaddr)) < 0)
	{
		perror("fail to bind");
		exit(-1);
	}

	listen(listenfd, 5);

	signal(SIGCHLD, handler);
	struct sockaddr_in  peeraddr;
	socklen_t peerlen;
	peerlen = sizeof(peeraddr);
	while ( 1 )
	{
		connfd = accept(listenfd, (struct sockaddr *)&peeraddr, &peerlen);
		printf("connfd:%d\t",connfd);
		if ((connfd) < 0)
		{
			perror("fail to accept");
			exit(-1);
		}
		if ((pid = fork()) < 0)
		{
			perror("fail to fork");
			exit(-1);
		}
		else if (pid == 0)
		{
			while (recv(connfd, buf, N, 0) >0)
			{
				printf("%s:%s", inet_ntoa(peeraddr.sin_addr), buf);
				send(connfd, buf, N, 0);
			}
			exit(0);
		}
		else
		{
			printf("close connfd:%d\n",connfd);
			close(connfd);
		}
	}

	return 0;
}
