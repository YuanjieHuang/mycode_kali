#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct sockaddr SA;

#define  N  64

int main(int argc, char *argv[])
{
	int sockfd;
	char buf[N];
	struct sockaddr_un servaddr, peeraddr;
	socklen_t peerlen;

	if (argc < 2)
	{
		printf("Usage : %s <servsock_path>\n", argv[0]);
		return -1;
	}

	// XXX int socket(int domain, int type, int protocol);
	if ((sockfd = socket(PF_UNIX, SOCK_DGRAM, 0)) < 0)
	{
		perror("fail to socket");
		exit(-1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sun_family = PF_UNIX;
	strcpy(servaddr.sun_path, argv[1]);
	remove(argv[1]);	

	// XXX int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	if (bind(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("fail to bind");
		exit(-1);
	}

	peerlen = sizeof(peeraddr);
	bzero(&peeraddr, sizeof(peeraddr));
	while ( 1 )
	{
		recvfrom(sockfd, buf, N, 0, (SA *)&peeraddr, &peerlen);
		printf("recv from client : %s", buf);
		sendto(sockfd, buf, N, 0, (SA *)&peeraddr, peerlen);
	}

	return 0;
}
