#include "stdio.h"
#include "math.h"
/*
    计算定积分：(x^4+x^3+1)dx  [0,1] 
*/
float func(float x)
{
    return pow(x,4)+pow(x,3)+1;
}

float x(float a,float b,int k)
{
    return a+k*(b-a)/4  ;
}

float ING(float a,float b)
{
    return ((b-a)/90)*(7*func(x(a,b,0))+32*func(x(a,b,1))+
    12*func(x(a,b,2))+32*func(x(a,b,3))+7*func(x(a,b,4)));
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

