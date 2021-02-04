#include <stdio.h>
#include <string.h>
void main()
{
   char *p;
   char a[20]="asdfghasdf";
   p=memchr(a,'f',10);
 
   printf("%c\n",*p);

}
