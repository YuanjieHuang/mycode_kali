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
	int sockfd;
	struct sockaddr_in peeraddr;
	char buf[N] = "This is a multicast package\n";

	if (argc < 3)
	{
		printf("Usage : %s <ip> <port>\n", argv[0]);
		exit(-1);
	}

	// XXX int socket(int domain, int type, int protocol);
	if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("fail to socket");
		exit(-1);
	}

	// XXX int bind(int sockfd, const struct sockaddr *addr,
	//              socklen_t addrlen);
	bzero(&peeraddr, sizeof(peeraddr));
	peeraddr.sin_family = PF_INET;
	peeraddr.sin_port = htons(atoi(argv[2]));
	peeraddr.sin_addr.s_addr = inet_addr(argv[1]);
	
	/*
	int on = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)) < 0)
	{
		perror("fail to setsockopt");
		exit(-1);
	}
	*/
	while ( 1 )
	{
		sendto(sockfd, buf, N, 0, (SA *)&peeraddr, sizeof(peeraddr));
		sleep(1);
	}

	return 0;
}
