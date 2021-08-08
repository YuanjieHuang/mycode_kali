/***********************Procedure Einstein's question*******************************/
#include <string.h> 
#include <stdio.h> 
/*
    有一长阶梯，若每步上2阶，最后剩1阶；若每步上3阶，最后剩2阶；
    若每步上4阶，最后剩3阶；若每步上5阶，最后剩4阶；若每步上6阶，最后剩5阶；
    只有每步上7阶，最后剩1阶不剩。求：阶梯最少阶数？
*/
void main()
{
    int x=7,i,res,flag=0;
    for(i=1;i<=100;i++)                                /*将循环次数定为100*/
    {
        if((x%2==1)&&(x%3==2)&&(x%5==4)&&(x%6==5) )  /*如果x符合题目叙述的要求*/
        {
            res=x;
            flag=1;
            break;                                      /*跳出循环，不再进行比较*/
        }
        x=7*(i+1);
    }
    if(1==flag)
        printf("The result of Einstein's question is %d",res);      /*输出答案*/
    else
        printf("In this rage cannot get result\n ");             /*在程序限定的范围内找不到答案*/
}

