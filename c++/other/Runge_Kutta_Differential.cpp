#include<stdio.h>

#include<math.h>

#define f(x,y) (-1*(x)*(y)*(y))

int main()

{

double a,b,x0,y0,k1,k2,k3,k4,h;

int n,i;

printf("input a,b,x0,y0,n:");

scanf("%lf%lf%lf%lf%d",&a,&b,&x0,&y0,&n);

printf("x0\ty0\tk1\tk2\tk3\tk4\n");

for(h=(b-a)/n,i=0;i!=n;i++)

{

k1=f(x0,y0);

k2=f(x0+h/2,y0+k1*h/2);

k3=f(x0+h/2,y0+k2*h/2);

k4=f(x0+h,y0+h*k3);

printf("%lf\t%lf\t",x0,y0);

printf("%lf\t%lf\t",k1,k2);

printf("%lf\t%lf\n",k3,k4);

y0+=h*(k1+2*k2+2*k3+k4)/6;

x0+=h;

}

printf("xn=%lf\tyn=%lf\n",x0,y0);

return 0; 
}
