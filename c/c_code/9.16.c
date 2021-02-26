#include <stdio.h>
int *max(int *i ,int *j)
{
    int *p;
    if(*i>*j)
    {
       p=i;
    }
    else
    {
       p=j;
    }
    return(p);
}
 
int main()
{
   int i ,j ;
   int *q;
   i=5;
   j=3;
   q=max(&i,&j);
   printf("max = %d" ,*q);
}
