#include <stdio.h>
#include <string.h>
main()
{
   char a[20]="asdfghijk";
   printf("%s\n",a);
   memset(a,'W',3);
   printf("%s\n",a);
   memset(a,'x',6);
   printf("%s\n",a);
}
