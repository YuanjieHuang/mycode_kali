#include <stdio.h>
#if 0
//穷举算法：
int exaustive(int head, int foot, int *chicken, int *rabbit)
{
    for(i = 0; i <= head; i++)
    {
        j = head - i;
        if(i*2 + j*4 == foot)
        {
            *chicken = i;
            *rabbit = j;
            return 1;
        }
    }
    return 0;
}
#endif
/*
分治算法：将问题分解成M个规模较小的子问题，这些子问题互相独立，并且于原问题形式相同；
递归解决这些子问题；将子问题的解合并得到原问题的解。
*/
#define MAXNUM 30

int falseCoin(int coin[], int low, int high)
{
    int i, sum1, sum2, sum3;
    int re;
    sum1 = sum2 = sum3 = 0;
    if(low + 1 == high)
    {
        if(coin[low] < coin[high])
        {
            re = low + 1;
            return re;
        }
        else
        {
             re = high + 1;
             return re;
        }
    }
    if((high - low + 1) % 2 ==0)
    {
        for(i=low; i<low + (high - low)/2; i++)
        {
            sum1= sum1 + coin[i];
        }
        for(i=low+(high - low)/2 + 1; i<=high; i++)
        {
            sum2 = sum2 + coin[i];
        }
        if(sum1>sum2)
        {
            re = falseCoin(coin, low+(high - low)/2 + 1, high);
            return re;
        }
        else if(sum1 < sum2)
        {
            re = falseCoin(coin, low, low+(high - low)/2);
            return re;
        }
        else
        {
                
        }
    }
    else
    {
        for(i = low;i<=low+(high-low)/2-1;i++)
        {
            sum1= sum1 + coin[i]
        }
        for(i=low+(high-low)/2+1;i<=high;i++)
        {
            rum2 = sum2 + coin[i];
        }
        sum3 = coin[llow+(high-low)2];
        if(sum1>sum2)
        {
            re = falseCoin(coin, low+(high-low)/2,high);
            return re;
        }
        else if (sum1<sum2)
        {
            re = falseCoin(coin,low,low+(high-low)/2);
            return re;
        }
        else
        {
                
        }
        if(sum1+sum3 == sum2+sum3)
        {
            re = low + (high -low)/2 +1;
            return re;
        }
    }
}

