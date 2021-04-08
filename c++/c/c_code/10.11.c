#include <stdlib.h>
#include <stdio.h>
int main()
{
   float a,b ;
   char  *p;
   int po,sign;
   a=123.45;
   b=-2345.754;
   p=ecvt(a,4,&po,&sign);
   printf("float:%f  string :%s  howmany:4 dot:%d sign:%d\n",a,p,po,sign);
   p=ecvt(b,4,&po,&sign);
   printf("float:%f  string :%s  howmany:4 dot:%d sign:%d\n",b,p,po,sign);
   return 0;
}



