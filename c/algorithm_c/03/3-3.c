#include "stdio.h"
/*
递归算法：直接或间接使用原算法本身
    注意点：
    1.必须有一个非递归定义的初始值，作为递归结束标志，或递归结束出口；
    2.问题许具有递归性，即反复调用自身过程的特性；
*/
int P(int n,int m)
{
    if(m==1 || n == 1) return 1;
    if(m>n) return P(n,n);
    if(m==n) return 1+P(n,m-1);
    return P(n,m-1)+P(n-m,m);
}

main()
{
    int n,s;
    printf("Please input a integer for getting the number of division\n");
    scanf("%d",&n);                    /*输入正整数n*/
    s =    P(n,n);                    /*求出正整数n的划分数*/
    printf("The number of division of %d is %d\n",n,s);
}

