#include "stdio.h"
/*
    5渔夫，A将鱼分5份，余1，扔之，拿走一份；B将剩余鱼分5份，余1，仍之，拿走一份
    C、D、E同法，求鱼总数？
*/

int getfish(int init,int n)
{
   int s = init;
   while(n)
   {
        s = 5*s+1 ;
        n--;
   }
   return s;
}

main()
{
    printf("Fish which were gotten by fishers at least are %d",getfish(6,4));//Input para?
}
