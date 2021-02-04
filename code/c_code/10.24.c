#include <stdio.h>
#include <string.h>
main()
{
   char *p,*q;
   char a[20]="asdfghasdf";
   p=strchr(a,'s');
   q=strchr(a,'d');
   printf("%c\n",*p);
   printf("%c\n",*q);
 
}
