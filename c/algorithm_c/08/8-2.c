#include "stdio.h"
/*
    计算定积分：(2x+3)dx  [0,1] 
*/
float func(float x)
{
    return 2*x+3;
}

float ING(float a,float b)
{
    return (b-a)/2*(func(a)+func(b));
}

main()
{
    float a,b;
    printf("Please input the low & high limitation and the accuracy\n");
    printf("Low limitation:");
    scanf("%f",&a);
    printf("High limitation:");
    scanf("%f",&b);
    printf("The result of integration is %f",ING(a,b));
}

