#include <stdio.h>
#include <string.h>
void main()
{
   char a[20]="asddafdxcdfgh";
   char b[20]="ijaeraewklmn";
   char *s;
   printf("%s\n%s\n",a,b);
   s=memccpy(a,b,'k',30);
   printf("%c\n",*s);
   printf("%s\n%s\n",a,b);
}
