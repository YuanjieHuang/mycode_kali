#include <stdio.h>
#include <netdb.h>   

int  main()
{
	int i=0;
    struct servent *ser;
    while( ser=getservent())
    { if (i>20) break;i++;
       printf("name : %s  ",ser->s_name);
       printf("port : %d  ",ntohs(ser->s_port));
       printf("protocol:%s  ",ser->s_proto);
       printf("alias: %s\n",ser->s_aliases[0]);
    }
}
