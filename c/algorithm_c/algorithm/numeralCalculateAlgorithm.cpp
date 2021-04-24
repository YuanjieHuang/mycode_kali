#include <stdio.h>
#include <math.h>

double SQRT(double inputVal)//迭代法开方运算
{
    double squareRoot = inputVal, iteratorVal = 0.0;//迭代初值
    while ((fabs(squareRoot - iteratorVal)) > 0.00001)
    {
        iteratorVal = squareRoot;
        squareRoot = 0.5*(iteratorVal + inputVal/iteratorVal);
    }
    return squareRoot;
}

/*
    求（0，1）间sinx/x的定积分
*/

double integrand(double x)//被积函数
{
    if(x != 0)
    {
        return sin(x) / x;
    }
    else
    {
        return 1.0;
    }
}

double integral(double lowLimit, double highLimit, double accuracy)
{
    double T1 = 0.0, T2 = 0.0, s = 0.0, h, x;
    int flag;
    h = highLimit - lowLimit;
    T1 = h/2*(integrand(lowLimit) + integrand(highLimit));
    do
    {
        s = 0;
        x = lowLimit + h/2;
        while (x < highLimit)
        {
            s = s + integrand(x);
            x = x + h;
        }
        T2 = T1/2 + h/2*s;
        if(fabs(T1 - T2) >= accuracy)
        {
            h = h/2;
            T1 = T2;
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        
    } while (flag);
    return T2;
}


int main()
{
    double inputVal = 2;
    printf("SQRT(%f)=%f\n", inputVal, SQRT(inputVal));
    printf("integral(0,1,0.000001)=%f\n", integral(0,1,0.000001));
}