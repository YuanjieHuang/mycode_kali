#include "stdio.h"
main()
{
    int a,b;
    a=5;
    b=10;
    printf("a=%d,b=%d\n",a,b);//a=5,b=10
    a=a^b;
    b=b^a;                    //b=b^(a^b)=a
    a=a^b;                    //a=(a^b)^a=b
    printf("a=%d,b=%d\n",a,b);//a=10,b=5
}

