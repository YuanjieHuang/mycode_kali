#include <stdlib.h>
#include <stdio.h>
int main()
{
   char a[8]="-123.45";
   char b[6]="23.456";
   char c[6]="-1234";
   char d[6]="123asd";
   char e[6]="12a12";
   float x,y,z,m,n ;
   x=atof(a);
   y=atof(b);
   z=atof(c);
   m=atof(d);
   n=atof(e);
   printf("string: %s  float: %f\n",a,x);
   printf("string: %s  float: %f\n",b,y);
   printf("string: %s  float: %f\n",c,z);
   printf("string: %s  float: %f\n",d,m);
   printf("string: %s  float: %f\n",e,n);
}


