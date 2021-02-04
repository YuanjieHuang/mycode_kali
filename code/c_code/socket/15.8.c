#include <stdio.h>
#include <netdb.h>   

int  main()
{
    struct servent *ser;
   
    if( ser=getservbyport(htons(23),"tcp"))
    {
       printf("name : %s\n",ser->s_name);
       printf("port : %d\n",ntohs(ser->s_port));
       printf("protocol:%s\n",ser->s_proto);
       printf("alias: %s\n",ser->s_aliases[0]);
    }
    else
    {
    	printf("there is no such a service.\n");
    }
   
    if( ser=getservbyport(htons(80),"tcp"))
    {
       printf("name : %s\n",ser->s_name);
       printf("port : %d\n",ntohs(ser->s_port));
       printf("protocol:%s\n",ser->s_proto);
       printf("alias: %s\n",ser->s_aliases[0]);
    }
    else
    {
    	printf("there is no such a service.\n");
    }
    
    if( ser=getservbyport(htons(61111),"tcp"))
    {
       printf("name : %s\n",ser->s_name);
       printf("port : %d\n",ntohs(ser->s_port));
       printf("protocol:%s\n",ser->s_proto);
       printf("alias: %s\n",ser->s_aliases[0]);
    }
    else
    {
    	printf("there is no such a service.\n");
    }
 }
