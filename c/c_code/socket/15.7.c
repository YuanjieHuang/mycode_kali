#include <stdio.h>
#include <netdb.h>   

int  main()
{
    struct servent *ser;
    if( ser=getservbyname("ftp","tcp"))
    {
       printf("name : %s\n",ser->s_name);
        printf("port : %d  ",ntohs(ser->s_port));
       printf("protocol:%s\n",ser->s_proto);
       printf("alias: %s\n",ser->s_aliases[0]);
    }
    else
    {
    	printf("there is no such a service.\n");
    }
     if( ser=getservbyname("http","tcp"))
    {
       printf("name : %s\n",ser->s_name);
 printf("port : %d  ",ntohs(ser->s_port));
       printf("protocol:%s\n",ser->s_proto);
       printf("alias: %s\n",ser->s_aliases[0]);
    }
    else
    {
    	printf("there is no such a service.\n");
    }
        if( ser=getservbyname("asdasd","tcp"))
    {
       printf("name : %s\n",ser->s_name);
      printf("port : %d  ",ntohs(ser->s_port));
       printf("protocol:%s\n",ser->s_proto);
       printf("alias: %s\n",ser->s_aliases[0]);
    }
    else
    {
    	printf("there is no such a service.\n");
    }   
}
