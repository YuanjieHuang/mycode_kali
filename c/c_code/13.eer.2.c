#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(void)
{ 
   printf("ENOENT:\n");
   char *mesg = strerror(ENOENT);
   printf("  Errno  :%d\n",ENOENT);
   printf("  Message:%s\n",mesg);

   printf("EIO	:\n");
   char *mesg1 = strerror(EIO);
   printf("  Errno  :%d\n",EIO);
   printf("  Message:%s\n",mesg1);

   printf("EEXIST	:\n");
   char *mesg2 = strerror(EEXIST);
   printf("  Errno  :%d\n",EEXIST);
   printf("  Message:%s\n",mesg2);
   int i;
   for(i=1;i<=15;i++)
   {
   	  printf("Errno:%d  ",i);
      printf("Message:%s\n",strerror(i));
   }
}
