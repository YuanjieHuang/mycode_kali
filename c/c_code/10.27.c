#include <stdio.h>
#include <string.h>
main()
{
   char a[20]="qweaQWEa^*&aIOP";
   char b[]="qwer";
   int i,j;
   i=strlen(a);
   j=strlen(b);
   printf("%d\n",i);
   printf("%d\n",j);
}
