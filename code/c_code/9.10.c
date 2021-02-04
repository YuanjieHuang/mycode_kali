#include <stdio.h>
int aa(int x)			
{
   x = x*x;		
   return(x);	
}
main()
{
   int x,y;
   x=5;
   y=aa(x);
   printf("X: %d Y: %d\n",x,y);
}

