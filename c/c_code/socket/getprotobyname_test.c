#include <stdio.h>
#include <netdb.h>   

int  main()
{
    struct protoent *pro;
    pro=getprotobyname("icmp");
    printf("protocol name : %s\n",pro->p_name);
    printf("protocol number : %d\n",pro->p_proto);
    printf("protocol alias: %s\n",pro->p_aliases[0]);
    pro=getprotobyname("udp");
    printf("protocol name : %s\n",pro->p_name);
    printf("protocol number : %d\n",pro->p_proto);
    printf("protocol alias: %s\n",pro->p_aliases[0]);
    pro=getprotobyname("tcp");
    printf("protocol name : %s\n",pro->p_name);
    printf("protocol number : %d\n",pro->p_proto);
    printf("protocol alias: %s\n",pro->p_aliases[0]);
}
