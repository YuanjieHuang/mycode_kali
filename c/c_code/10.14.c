#include <stdio.h>
#include <string.h>
void main()
{
   char a[20]="asdfgQWERT";
   char b[20]="asdfgqwERT";
   int i,j;
   i=memcmp(a,b,5);
   j=memcmp(a,b,7);
   printf("memcpy %s , %s ,5 charactor ,result : %d \n",a,b,i);
   printf("memcpy %s , %s ,7 charactor ,result : %d \n",a,b,j);
}
