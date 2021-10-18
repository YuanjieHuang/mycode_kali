#include <stdlib.h>
#include <stdio.h>
int main()
{
   char a[8]="123567";
   char b[8]="-45645";
   char c[8]="5645.234";
   char d[8]="0.135";
   char e[8]="5675asd";
   long x,y,z,n,m ;
   x=atol(a);
   y=atol(b);
   z=atol(c);
   n=atol(d);
   m=atol(e);
   printf("string: %s  long: %ld\n",a,x);
   printf("string: %s  long: %ld\n",b,y);
   printf("string: %s  long: %ld\n",c,z);
   printf("string: %s  long: %ld\n",d,n);
   printf("string: %s  long: %ld\n",e,m);
}



