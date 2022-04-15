#include<stdio.h>
#include "matrix.h"

//输出存储的稀疏矩阵
void display(TSMatrix M);

int main() 
{
    TSMatrix M;
    M.m=3;
    M.n=3;
    M.num=3;
    M.data[0].i=1;
    M.data[0].j=1;
    M.data[0].e=1;
    M.data[1].i=2;
    M.data[1].j=3;
    M.data[1].e=5;
    M.data[2].i=3;
    M.data[2].j=1;
    M.data[2].e=3;
    display(M);
    return 0;
}

void display(TSMatrix M)
{
    for(int i=1;i<=M.n;i++)
    {
        for(int j=1;j<=M.m;j++)
        {
            int value =0;
            for(int k=0;k<M.num;k++)
            {
                if(i == M.data[k].i && j == M.data[k].j)
                {
                    printf("%d ",M.data[k].e);
                    value =1;
                    break;
                }
            }
            if(value == 0)
                printf("0 ");
        }
        printf("\n");
    }
}