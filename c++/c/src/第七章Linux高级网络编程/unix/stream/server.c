#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N 64

typedef struct sockaddr SA;

int main(int argc, char *argv[])
{
	int listenfd, connfd;
	struct sockaddr_un myaddr, peeraddr;
	socklen_t peerlen;
	char buf[N];

	if (argc < 2)
	{
		printf("Usage : %s <sock_file>\n", argv[0]);
		exit(-1);
	}

	// XXX int socket(int domain, int type, int protocol);
	if ((listenfd = socket(PF_UNIX, SOCK_STREAM, 0)) < 0)
	{
		perror("fail to socket");
		exit(-1);
	}

	// XXX int bind(int sockfd, const struct sockaddr *addr,
	//              socklen_t addrlen);
	bzero(&myaddr, sizeof(myaddr));
	myaddr.sun_family = PF_UNIX;
	strcpy(myaddr.sun_path, argv[1]);
	remove(argv[1]);
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
		printf("connection from [%s]\n", peeraddr.sun_path);
		recv(connfd, buf, N, 0);
		printf("recv from client : %s\n", buf);
		strcpy(buf, "Welcome to Farsight Server");
		send(connfd, buf, N, 0);
		close(connfd);
	}

	return 0;
}
