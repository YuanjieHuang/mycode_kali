#include "stdio.h"
/*
角谷猜想：任意给定一个自然数，若它为偶数则除以2，若它为奇数则乘以3加1，得到一个新的自然数。
    按照这样的计算方法计算下去，若干次后得到的结果必然为1.
*/
proveJiaoGu(int n)
{
    int count=1;
    while(n!=1 && count<=1000){   /*阈值设为1000*/
    if(n%2==0)   /*n为偶数*/
    {
        printf("%d/2=%d\n",n,n/2);
        n = n/2;
     }
    else
    {
        printf("%d*3+1=%d\n",n,n*3+1); /*n为奇数*/
        n=n*3+1;
    }
    count++;
    }
    if(count<1000 && n==1)
        printf("This natural number  is according to JiaoGu Guess\n");
}

main()
{
    int n;
    printf("Please input a number to verify\n");
    scanf("%d",&n);
    printf("-------- Step of Verification---------\n");
    proveJiaoGu(n);
}
