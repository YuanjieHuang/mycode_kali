#include "stdio.h"
//计算数列1，3，6，13，26，53，...
unsigned long func(int n)
{
    if(n==1)
        return 1;
    if(n % 2 == 0)
        return 2*func(n-1)+1;
    if(n % 2 != 0)
        return 2*func(n-1);
}

main()
{
    printf("The 10th item of the sequence is %ld",func(20));		/*直接输出结果*/
}
