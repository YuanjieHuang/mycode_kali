
#include <stdio.h>

int addn(x)
{
   int s;
   if(x==1)
   {
      s=1;
   }
   else
   {
      s=x + addn(x-1);
   }
   return(s);
}
int main()
{
    int i=100;
    int j;
    j=addn(100);
    printf("result: %d",j);
}
