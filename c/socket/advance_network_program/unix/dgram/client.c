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
	struct sockaddr_un servaddr, cliaddr;

	if (argc < 3)
	{
		printf("Usage : %s <servsock_path> <clisock_path>\n", argv[0]);
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

	bzero(&cliaddr, sizeof(cliaddr));
	cliaddr.sun_family = PF_UNIX;
	strcpy(cliaddr.sun_path, argv[2]);

	remove(argv[2]);
	// XXX int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	if (bind(sockfd, (SA *)&cliaddr, sizeof(cliaddr)) < 0)
	{
		perror("fail to bind");
		exit(-1);
	}

	while ( 1 )
	{
		printf("client > ");
		fgets(buf, N, stdin);
		if (strcmp(buf, "quit\n") == 0) break;
		sendto(sockfd, buf, N, 0, (SA *)&servaddr, sizeof(servaddr));
		bzero(buf, N);	
		recvfrom(sockfd, buf, N, 0, NULL, NULL);
		printf("recv from server : %s", buf);
	}
	close(sockfd);

	return 0;
}
