#include "stdio.h"
/*
贪心算法：
    最优装船问题：
        载重C一定，集装箱质量由用户输入，如何装集装箱最多最多？
*/
void sort(int w[], int t[], int n)
{
    int i,j,tmp;
    int *w_tmp= (int *)malloc(sizeof(int) * n);/*动态开辟一个临时数组，存放w[]中的内容，用于排序*/
    for(i=0;i<n;i++)
        t[i] = i;                            /*初始化数组t*/
    for(i=0;i<n;i++)
        w_tmp[i] = w[i];
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)                /*冒泡排序实现*/
            if(w_tmp[j]>w_tmp[j+1])
            {
                tmp = w_tmp[j];
                w_tmp[j] = w_tmp[j+1];
                w_tmp[j+1] = tmp;
                tmp = t[j];
                t[j] = t[j+1];
                t[j+1] = tmp;
            }
}

void Loading(int x[],int w[],int c,int n)
{
    int i , s = 0 ;
    int *t = (int *)malloc(sizeof(int) * n); /*动态开辟一个临时数组，存放w[]的下标，如果t[i],t[j],i<j，则w[i]≤w[j]*/
    sort(w,t,n);                        /*排序，用数组t[]存放w[]的下标*/
    for(i = 0;i<n;i++)
    x[i] = 0;        /*初始化数组x[]*/
    for(i=0;i<n && w[t[i]]<=c; i++){
        x[t[i]] = 1;                    /*将第t[i]个集装箱装入货船中*/
        c = c - w[t[i]];                /*变量c中存放货船的剩余载重量*/
        }
}

main()
{
    int x[5], w[5] = {5,7,6,3,4}, c = 13, i;
    printf("Please input the maximum loading of the sheep\n");
    // scanf("%d",&c);                        /*输入货船的最大载重量*/
    printf("Please input the weight of FIVE box\n");
    // for(i=0;i<5;i++)                        /*输入每个集装箱的重量*/
    //     scanf("%d",&w[i]);
    Loading(x,w,c,5);                    /*进行最优装载*/
    printf("The following boxes will be loaded\n");
    for(i=0;i<5;i++)                        /*输出结果*/
    {
        if(x[i] == 1)     printf("BOX:%d ",i) ;
    }
}

