#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int  main()
{
	char cp[]="192.168.1.1";
	printf("%ld\n",inet_addr(cp));
}
