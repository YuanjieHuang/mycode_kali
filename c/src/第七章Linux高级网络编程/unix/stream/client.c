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
	int sockfd;
	struct sockaddr_un servaddr;
	char buf[N] = "Hello Server";

	if (argc < 2)
	{
		printf("Usage : %s <sock_file>\n", argv[0]);
		exit(-1);
	}

	// XXX int socket(int domain, int type, int protocol);
	if ((sockfd = socket(PF_UNIX, SOCK_STREAM, 0)) < 0)
	{
		perror("fail to socket");
		exit(-1);
	}

	// XXX int bind(int sockfd, const struct sockaddr *addr,
	//              socklen_t addrlen);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sun_family = PF_UNIX;
	strcpy(servaddr.sun_path, argv[1]);
	if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("fail to connect");
		exit(-1);
	}

	send(sockfd, buf, N, 0);
	recv(sockfd, buf, N, 0);
	printf("recv from server : %s\n", buf);
	close(sockfd);

	return 0;
}
