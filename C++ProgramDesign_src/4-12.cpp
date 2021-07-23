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
