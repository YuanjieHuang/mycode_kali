#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N 64

typedef struct sockaddr SA;

int main(int argc, char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;
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

	// XXX int bind(int sockfd, const struct sockaddr *addr,
	//              socklen_t addrlen);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = PF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);
	
	struct timeval t = {3, 0};
	if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &t, sizeof(t)) < 0)
	{
		perror("fail to setsockopt");
		exit(-1);
	}
	if (recvfrom(sockfd, &buf, N, 0, NULL, NULL) < 0)
	{
		printf("errno = %d : %s\n", errno, strerror(errno));
	}

	return 0;
}
