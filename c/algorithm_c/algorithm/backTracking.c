#include <stdio.h>

int canPalceQueen(int i, int j, int (*Q)[4])
{
    int s,t;
    for(s=i,t=0;t<4;t++)//判断行
    {
        if(Q[s][t] == 1 && t !=j)
        {
            return 0;
        }
    }
    for(t=j,s=0;s<4;s++)//判断列
    {
        if(Q[s][t] == 1 && s != i)
        {
            return 0;
        }
    }
    for(s=i-1,t=j-1;s>=0 && t>=0;s--,t--)//判断左上方
    {
        if(Q[s][t] == 1)
        {
            return 0;
        }
    }
    for(s=i+1,t=j+1;s<4&&t<4;s--,t++)//判断右下方
    {
        if(Q[s][t] == 1)
        {
            return 0;
        }
    }
    for(s=i-1,t=j+1;s>=0 && t<4;s--,t++)//判断右上方
    {
        if(Q[s][t] == 1)
        {
            return 0;
        }
    }
    for(s=i+1,t=j-1;s<4 && t>=0;s++, t--)//判断左下方
    {
        if(Q[s][t] == 1)
        {
            return 0;
        }
    }
    return 1;
}

void setQueen(int j, int (* Q)[4])
{
    int i,k;
    if(j==4)
    {
        for(i=0;i<4;i++)
        {
            for(k=0;k<4;k++)
            {
                printf("%d",Q[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    for(i=0;i<4;i++)
    {
        if(canPalceQueen(i,j,Q))
        {
            Q[i][j] = 1;//palce a queen
            setQueen(j+1,Q);
            Q[i][j] = 0;
        }
    }
}

int main()
{
    int Q[4][4];
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            Q[i][j] = 0;
        }
    }
    setQueen(0,Q);
    // printf("The number of the answers of FOR_QUEEN are %d ",count)
}