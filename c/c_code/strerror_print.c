#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(void)
{ 
   for(int i=EPERM;i<=ERANGE;i++)
   {
   	printf("Errno:%d  ",i);
      printf("Message:%s\n",strerror(i));
   }
}
