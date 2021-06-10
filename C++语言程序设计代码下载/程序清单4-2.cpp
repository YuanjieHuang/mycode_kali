程序清单4-2
// ********************************************************
// getRoots.cpp
// 功能：主函数调用getRoots函数计算一元二次方程的实根
// ********************************************************

#include <cmath>
#include <iostream>

using namespace std;

void  getRoots ( float , float , float , float& , float& );

int main()
{
    float a, b, c, root1, root2;
    
    cout << "Please enter the 3 coefficients of a, b and c :" ;
    cin  >> a >> b >> c;
    
    getRoots( a, b, c, root1, root2 );
    
    cout << "The 2 roots are: " << endl << root1 << endl << root2 << endl;
    
    return 0;
}

void getRoots( float a, float b, float c, float& root1, float& root2)
// 计算系数为a,b,c的一元二次方程的实根
// 前置条件:	a,b,c已赋值,且b * b - 4.0 * a * c >= 0
// 后置条件:	root1和root2分别存放两个实根的值
{   
     float temp;			 
     
     temp = b * b - 4.0 * a * c;

     root1 = (-b + sqrt(temp) ) / ( 2.0 * a );
	root2 = (-b - sqrt(temp) ) / ( 2.0 * a );
}
