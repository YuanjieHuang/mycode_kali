#include <stdlib.h>
#include <stdio.h>
int main()
{
   char a[8]="-1234";
   char b[6]="123";
   char c[8]="-12.24";
   char d[6]="0.135";
   int x,y,z,n ;
   x=atoi(a);
   y=atoi(b);
   z=atoi(c);
   n=atoi(d);
   printf("string: %s  int: %d\n",a,x);
   printf("string: %s  int: %d\n",b,y);
   printf("string: %s  int: %d\n",c,z);
   printf("string: %s  int: %d\n",d,n);
}



