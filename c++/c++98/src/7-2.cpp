//文件名：7-2.cpp
//解一元二次方程的函数及其应用
#include <iostream>
#include <cmath>
using namespace std;

int SolveQuadratic(double a, double b, double c, double *px1, double *px2)	;

int main()
{   double a,b,c,x1,x2;
    int result;
    cout << "请输入a,b,c: ";  cin >> a >> b >> c; 
    result = SolveQuadratic(a, b, c, &x1, &x2); 

    switch (result) {
        case 0: cout << "方程有两个不同的根：x1 = " << x1 << "  x2 = " << x2; break;
        case 1: cout << "方程有两个等根：" << x1; break;
        case 2: cout << "方程无根"; break;
        case 3: cout << "不是一元二次方程";
    }

  return 0;
}

//这是一个解一元二次方程的函数，a,b,c是方程的系数，px1和px2是存放方程解的地址
//函数的返回值表示根的情况：0--有两个不等根
//         		    1--有两个等根，在px1中
//            	            2--根不存在
//          		    3--降级为一元一次方程
int SolveQuadratic(double a,double b,double c, double *px1,double *px2)	
{   double disc, sqrtDisc;

    if(a == 0) return 3; //不是一元二次方程 

    disc = b * b - 4 * a * c;

    if( disc < 0 ) return 2; //无根

    if ( disc == 0 ) { *px1 = -b /(2 * a); return 1;}  //等根

    //两个不等根
    sqrtDisc = sqrt(disc);
    *px1 = (-b + sqrtDisc) / (2 * a);
    *px2 = (-b - sqrtDisc) / (2 * a);
    return 0;
}

