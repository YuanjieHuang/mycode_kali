程序清单4-13
// *************************************************************
// powerRecursion.cpp
// 用递归方式求x的k次方（k >= 1）
// *************************************************************

#include <iostream>
using namespace std;

int power( int, int );

int main()
{
	int base, exp;  // 基和幂次

	cout << "Enter the base and the exponent:";
	cin >> base >> exp;
	cout << "The result is " << power( base, exp ) << endl;

    return 0;
}

int power( int x, int k)
{
	if( k == 1 )
		return x;  // 基本条件
	else
		return x * power( x, k-1 );  // 更小版本
}
