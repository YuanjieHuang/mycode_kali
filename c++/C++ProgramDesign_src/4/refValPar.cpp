// ***************************************************
// refValPar.cpp
// 功能：演示引用形参与值形参的比较
// ***************************************************
#include <cmath>
#include <iostream>
using namespace std;
void valPara( int );
void refPara( int& );
int main()
{
    int x1, x2;
    x1 = 1;
    x2 = 1;
    valPara( x1 );
    refPara( x2 );
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    return 0;
}
void valPara( int x )
{
	x++;
}
void refPara( int& x )
{
    x++;
}
