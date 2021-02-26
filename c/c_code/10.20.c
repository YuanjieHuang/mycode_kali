#include <stdio.h>
#include <string.h>
void main()
{
   int i;
   char a[20]="asdfghijk";
   bzero(a,3);
   for(i=0;i<6;i++)
   {
      printf("%c\n",a[i]);
    }

}
