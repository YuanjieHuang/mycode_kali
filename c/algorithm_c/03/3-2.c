#include "stdio.h"
/*
    TOM共有5本新书，要借给A、B、C3位同学，每人只能借一本书，则TOM可以有多少种不同的借书方法。
*/
main()
{
    int i,j,k,count=0;
    printf("There are different methods for TOM to distribute his book to A,B,C\n");
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            for(k=1;k<=5;k++)
                if(i!=j && j!=k && i!=k){
                    printf("(%d,%d,%d) ",i,j,k);
                    count++;
                    }
    printf("The total medthods is %u\n",count);
}

