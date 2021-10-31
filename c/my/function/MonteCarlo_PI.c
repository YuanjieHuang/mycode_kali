/*
概率算法：
1.将问题转化为相应的几何图形S,S的面积是容易计算的，问题的结果往往对应几何图形中某一部分S1的面积；
2.然后，向几何图形中随即撒点；
3.统计几何图形S中和S1中的点数。根据S的面积和S1的面积关系以及各图形的点数来计算得到结果；
4.判断上述结果是否在需要的精度之内，如果未达到精度则进行执行步骤2。如果达到精度，则输出近似结果。
常用有：数值概率算法，蒙特卡洛Monte Carlo，拉斯维加斯Las Vegas，舍伍德Sherwood算法。
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
double montoPI(int n)
{
    double PI;
    double x, y;
    int i, sum;
    sum = 0;
    srand(time(NULL));
    for(i=1;i<n;i++)
    {
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;
        if(x*x + y*y <= 1)
        {
            sum++;
        }
        PI = 4.0*sum/n;
    }
    return PI;
}
void main()
{
    int n;
    double PI;
    printf("Monto Carlo calculate PI\n");
    printf("Input dots number:\n");
    scanf("%d", &n);
    PI = montoPI(n);
    printf("PI=%f\n",PI);
}