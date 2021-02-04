#include <stdio.h>
#include <netdb.h>   

int  main()
{
    struct protoent *pro;
    int i;
    
    for(i=0;i<5;i++)
    {
    pro=getprotobynumber(i);
    printf("protocol name : %s\n",pro->p_name);
    printf("protocol number : %d\n",pro->p_proto);
    printf("protocol alias: %s\n",pro->p_aliases[0]);
    }
}
