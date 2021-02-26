#include <stdio.h>
#include <string.h>
main()
{
   char *p;
   char a[20]="qweaQWEa^*&aIOP";
   char s[]="a";
   printf("%s\n",a);
   p=strtok(a,s);
   printf("%s\n",p);
   while(p=strtok(NULL,s))
   {
      printf("%s\n",p);
   }

}
