#include <string.h>
#include <stdio.h>
int answerNum = 0;

#if 0
int canPalceQueen(int row, int j, int (*Q)[8])
{
    int i,k,flag1 = 0,flag2=0,flag3=0,flag4=0,flag5=0;
    for(i=row,k=0;k<4;k++)//判断行
    {
        if(Q[i][k] == 1 && k !=j)
        {
            return 0;
        }
    }
    for(k=j,i=0;i<4;i++)//判断列
    {
        if(Q[i][k] == 1 && i != row)
        {
            return 0;
        }
    }
    for(i=row-1,k=j-1;i>=0 && k>=0;i--,k--)//判断左上方
    {
        if(Q[i][k] == 1)
        {
            return 0;
        }
    }
    for(i=row+1,k=j+1;i<4&&k<4;i--,k++)//判断右下方
    {
        if(Q[i][k] == 1)
        {
            return 0;
        }
    }
    for(i=row-1,k=j+1;i>=0 && k<4;i--,k++)//判断右上方
    {
        if(Q[i][k] == 1)
        {
            return 0;
        }
    }
    for(i=row+1,k=j-1;i<4 && k>=0;i++, k--)//判断左下方
    {
        if(Q[i][k] == 1)
        {
            return 0;
        }
    }
    return 1;
}
#endif


int canPalceQueen(int row, int j, int (*Q)[8])
{
    int i,k,flag1 = 0,flag2=0,flag3=0,flag4=0,flag5=0;
    for(i=0;i<8;i++)
    {
        if(*(*(Q+i)+j) != 0)
        {
            flag1 = 1;
            break;
        }
    }
    for(i=row, k=j;i>=0 && k>= 0;i--,k--)
    {
        if(*(*(Q+i)+k) != 0)
        {
            flag2 = 1;
            break;
        }
    }
    for(i=row, k=j;i>=0 && k>= 0;i--,k--)
    {
        if(*(*(Q+i)+k) != 0)
        {
            flag2 = 1;
            break;
        }
    }
    for(i=row, k=j;i<8 && k< 0;i++,k++)
    {
        if(*(*(Q+i)+k) != 0)
        {
            flag3 = 1;
            break;
        }
    }
    for(i=row, k=j;i>=0 && k<8;i--,k++)
    {
        if(*(*(Q+i)+k) != 0)
        {
            flag4 = 1;
            break;
        }
    }
    for(i=row, k=j;i<8 && k>= 0;i++,k--)
    {
        if(*(*(Q+i)+k) != 0)
        {
            flag2 = 1;
            break;
        }
    }
    if(flag1==1||flag2==1||flag3==1||flag4==1|flag5==1)
    {
        return 0
    }
    else 
    {return 1;}

}


/*
0-1矩阵表示棋盘，0代表空，1代表皇后
参数：row表示起始行；n表示列数为8；(*chess)[8]为指向每一行的指针
*/
void eightQueen(int row, int n, int (*chess)[8])
{
    int t,j,k,chess2[8][8];
    for(int i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        chess2[i][j] = *((*chess2+i)+j);
    }
    if(row == 8)
    {
        for(k=0;k<8;k++)
        {
            for(t=0;t<8;t++)
            {
                printf("%d  ",*(*(chess2+k)+t));
            }
            printf("\n");
        }
        printf("\n");
        answerNum++;
    }
    else
    {
        for(j=0;j<n;j++)
        {
            if(canPalceQueen(row,j,chess))
            {
                for(int i=0;i<8;i++)
                {
                    *((*chess2+row)+i)=0;
                }
                    *((*chess2+row)+j)=1;//row行j列
            }
            eightQueen(row+1,n,chess2);
        }
    }
}
void main()
{
    int chess[8][8] = {0};
    eightQueen(0, 8, chess);//*chess为指向棋盘每一行的指针
    printf("The number of the answer for eightqueen is\n");
    printf("%d\n\n",answerNum);
}