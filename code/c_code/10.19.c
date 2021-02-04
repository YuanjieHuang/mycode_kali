#include <stdio.h>
#include <string.h>
void main()
{
   char a[20]="asdfghijk";
   char b[20]="";
   char *p;
   p=strncpy(b,a,5);
   printf("%s\n",a);
   printf("%s\n",b);
   printf("%s\n",p);
}
