#include <stdio.h>

double polynomial1D(double a[], int n, double x)
{
    int i;
    double result;
    result = a[n-1];
    for(i=n-2; i>=0; i--)
    {
        result = result*x + a[i];
    }
    return result;
} 

void polynomial_mul(double A[], double B[], int n, double R[], int k)
{
    int i, j;
    for(i=0; i<k; i++)                  //初始化
    {
        R[i] = 0.0;
    }
    for(i=0; i<m; i++)                  //计算各项系数
    {
        for(j=0; j<n; j++)
        {
            R[i+j] += A[i]*B[j];
        }
    }
}

void main()
{
    int i;
    static double a[7] = {-15.0, -7.0, 7.0, 2.0, -3.0, 7.0, 3.0};
    static double x[6] = {-2.0, -0.5, 1.0, 2.0, 3.7, 4.0};
    double result;
    for(i=0; i<6; i++)
    {
        result = polynomial1D(a, 7, x[i]);
        printf("x=%5.21f,p(x)=%13.7e\n", x[i], result);
    }
    printf("\n");
}