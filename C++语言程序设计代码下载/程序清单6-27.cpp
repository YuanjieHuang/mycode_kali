程序清单6-27
// ********************************************************
// functionPointer.cpp
// 功能：介绍函数指针的基本概念
// ********************************************************

#include <iostream>
using namespace std;

int min( int a, int b )
{
return ( a < b ? a : b );
}

int main() 
{
int (*p)( int, int );	//① 

p = min;			//②
    
cout << "The min is: " << (*p)( 3, 4 );	//③ 

    return 0;
} 
