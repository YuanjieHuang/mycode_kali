#include "stdio.h"
/*
    计算组合数
*/
 int cnr(int m,int n)
 {
    if(m == n || n == 0)
        return 1;
    else
        return cnr(m-1,n) + cnr(m-1,n-1);
 }

 main()
 {
    int m,n;
    printf("Please input m and n for C(m,n)\n");
    scanf("%d %d",&m,&n);
    printf("C(%d,%d)=%d",m,n,cnr(m,n));
 }
