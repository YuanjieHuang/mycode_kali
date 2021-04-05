#include <string.h>
#include <stdio.h>
int x[100];
int val[100] = {-1};
int weight[100] = {-1};

int isOverLoad(int n, int c)
{
    int i, w=0;
    for(i=0;i<n;i++)
    {
        w = w + x[i] * weight[i];
    }
    if(w > c)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int getVal(int n)
{
    int i,v=0;
    for(i=0;i<=1;i++)
    {
        v = v + x[i] * val[i];
    }
    return v;
}

void knap_1(int n, int flag, int c, int *price)//找到物品报的最高价值量
{
    int i,j,p;
    if(isOverLoad(n,c)) return;//剪枝

    if(n == flag)
    {
        p = getVal(n);
        if(*price < p)
        {
            *price = p;
            return;
        }
    }
    for(i=0;i<=1;i++)
    {
        x[n] = i;
        knap_1(n+1,flag,c,price);
    }
}

void main()
{
    for(int i=0;i<100;i++)
    {
        printf("%d ",val[i]);
    }
}