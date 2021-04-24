#include <stdio.h>
#include <netdb.h>   

int  main()
{
    struct protoent *pro;
    while(pro=getprotoent()) 
    {printf("protocol name : %s  ",pro->p_name);
    printf("protocol number : %d  ",pro->p_proto);
    printf("protocol alias: %s\n",pro->p_aliases[0]);
    }
}
