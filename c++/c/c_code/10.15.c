#include <stdio.h>
#include <string.h>
void main()
{
   char a[20]="asdfgQWERT";
   char b[20]="asdfgqwFRT";
   int i,j,k;
   i=strncasecmp(a,b,5);
   j=strncasecmp(a,b,7);
   k=strncasecmp(a,b,8);
   printf("strncasecmp %s , %s ,5 charactor ,result : %d \n",a,b,i);
   printf("strncasecmp %s , %s ,7 charactor ,result : %d \n",a,b,j);
   printf("strncasecmp %s , %s ,8 charactor ,result : %d \n",a,b,k);

}
