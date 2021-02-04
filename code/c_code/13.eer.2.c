#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(void)
{ 
   int i;
   for(i=1;i<=15;i++)
   {
   	  printf("Errno:%d  ",i);
      printf("Message:%s\n",strerror(i));
   }
}
