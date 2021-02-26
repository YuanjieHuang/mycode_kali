#include <stdio.h>
#include <string.h>
main()
{
   char a[20]="asdfgQWERT!@$%";
   char b[20]="asdfgqwERT!@$%";
   if(memcmp(a,b,5)==0)
   {
      printf("same.\n");
   }
   else
   {
      printf("not same.\n");
   }
   if(memcmp(a,b,7)==0)
   {
      printf("same.\n");
   }
   else
   {
      printf("not same.\n");
   }

}
