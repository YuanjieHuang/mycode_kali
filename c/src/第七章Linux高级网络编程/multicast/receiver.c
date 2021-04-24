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
	struct sockaddr_in myaddr, peeraddr;
	socklen_t peerlen;
	struct ip_mreq mreq;
	char buf[N];

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

	bzero(&mreq, sizeof(mreq));
	mreq.imr_multiaddr.s_addr = inet_addr(argv[1]);
	mreq.imr_interface.s_addr = htonl(INADDR_ANY);
	if (setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0)
	{
		perror("fail to setsockopt");
		exit(-1);
	}

	// XXX int bind(int sockfd, const struct sockaddr *addr,
	//              socklen_t addrlen);
	bzero(&myaddr, sizeof(myaddr));
	myaddr.sin_family = PF_INET;
	myaddr.sin_port = htons(atoi(argv[2]));
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if (bind(sockfd, (SA *)&myaddr, sizeof(myaddr)) < 0)
	{
		perror("fail to bind");
		exit(-1);
	}
	/*
	int on = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)) < 0)
	{
		perror("fail to setsockopt");
		exit(-1);
	}
	*/
	peerlen = sizeof(peeraddr);
	while ( 1 )
	{
		recvfrom(sockfd, buf, N, 0, (SA *)&peeraddr, &peerlen);
		printf("[%s:%d] %s\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port), buf);
	}

	return 0;
}
