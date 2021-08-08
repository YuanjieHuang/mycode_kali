#include"stdio.h"
/*
    猴子第一天摘桃若干，当天吃掉其中一半还多一个，第二天吃掉剩余一半多一个，
    按照此吃法，到第十天剩下一个桃子。求，第一天摘的桃子数？
*/
main()
{
    int sum = 1,i;   /*sum 初始值为1，表示第十天的桃子数*/
    for(i=9;i>=1;i--)
         sum = (sum + 1) * 2 ;  /*每次循环都得出第i天的桃子数*/
    printf("The number of peach are %d\n",sum);
}

