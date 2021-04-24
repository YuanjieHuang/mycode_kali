#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int  main()
{
   struct in_addr ip;
   ip.s_addr=16885952;
   printf("%s\n",inet_ntoa(ip));
}
