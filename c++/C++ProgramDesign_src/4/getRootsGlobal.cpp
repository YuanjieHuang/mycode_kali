// *************************************************************
// getRootsGlobal.cpp
// 利用全局变量求一元二次方程的实根
// *************************************************************
#include <iostream>
#include <cmath>
using namespace std;
void getRoots( float a, float b, float c );
float root1, root2;
int main()
{
    float a, b, c;
    cout << "Please enter the 3 coefficients of a, b and c :" ;
    cin  >> a >> b >> c;
    getRoots( a, b, c );
    cout << "The 2 roots are: " << root1 << "  " << root2 << endl;
    return 0;
}
void  getRoots( float a, float b, float c )
{   
	float temp;			 
	temp = b * b - 4.0 * a * c;
	root1 = (-b + sqrt(temp) ) / ( 2.0 * a );
	root2 = (-b - sqrt(temp) ) / ( 2.0 * a );
}
void  getRoots(  /*in*/    float a,	// 一元二次方程系数
				/*in*/    float b,	// 一元二次方程系数
				/*in*/    float c,	// 一元二次方程系数
				/*out*/   float& root1,	// 一元二次方程第一个实根
				/*out*/   float& root2)	// 一元二次方程第二个实根
// 求以a, b, c为系数的一元二次方程的两个实根
// 前置条件：
//     a、b和c已赋值且b*b - 4*a*c >= 0
// 后置条件：
//     root1 = (-b + sqrt(b*b – 4*a*c)) / (2*a) 
//     root2 = (-b - sqrt(b*b – 4*a*c)) / (2*a)
{   
	float temp;					  // 求根过程中的b*b – 4*a*c
	temp = b * b - 4.0 * a * c;  // 求b*b – 4*a*c
     root1 = (-b + sqrt(temp) ) / ( 2.0 * a );  // 求两实根
     root2 = (-b - sqrt(temp) ) / ( 2.0 * a );
}
