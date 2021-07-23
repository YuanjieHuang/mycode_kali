// ***************************************************************
// invalidOverloading1.cpp
// 函数重载时容易出现的错误演示1
// ***************************************************************
#include <iostream>
using namespace std;
//函数原型
bool equal(int, int);
int  equal(int, int);
int main()
{
	int int1 = 0, int2 = 3;
	switch(equal (int1, int2)) {
		case true: 	
			cout << int1 << "==" << int2 << endl;
			break;
		case false:	
			cout << int1 << "!=" << int2 << endl; 
			break;	
	}
	return 0;
}
bool equal(int num1, int num2)
{
    if(num1 == num2)
        return true;
    else
        return false;
}
int equal(int num1, int num2)
{
    if(num1 == num2)
        return 1;
    else
        return 0;
}
