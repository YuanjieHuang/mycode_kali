#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N 64

typedef struct sockaddr SA;

int main(int argc, char *argv[])
{
	int listenfd, connfd;
	struct sockaddr_in myaddr, peeraddr;
	socklen_t peerlen;
	char buf[N];

	if (argc < 3)
	{
		printf("Usage : %s <ip> <port>\n", argv[0]);
		exit(-1);
	}

	// XXX int socket(int domain, int type, int protocol);
	if ((listenfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("fail to socket");
		exit(-1);
	}

	// XXX int bind(int sockfd, const struct sockaddr *addr,
	//              socklen_t addrlen);
	bzero(&myaddr, sizeof(myaddr));
	myaddr.sin_family = PF_INET;
	myaddr.sin_port = htons(atoi(argv[2]));
	myaddr.sin_addr.s_addr = inet_addr(argv[1]);
	if (bind(listenfd, (SA *)&myaddr, sizeof(myaddr)) < 0)
	{
		perror("fail to bind");
		exit(-1);
	}

	// XXX int listen(int sockfd, int backlog);
	if (listen(listenfd, 5) < 0)
	{
		perror("fail to listen");
		exit(-1);
	}

	peerlen = sizeof(peeraddr);
	while ( 1 )
	{
		if ((connfd = accept(listenfd, (SA *)&peeraddr, &peerlen)) < 0)
		{
			perror("fail to accept");
			exit(-1);
		}
		printf("connection from [%s:%d]\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));
		/*
		recv(connfd, buf, N, 0);
		printf("recv from client : %s\n", buf);
		strcpy(buf, "Welcome to Farsight Server");
		send(connfd, buf, N, 0);
		*/
		close(connfd);
	}

	return 0;
}
