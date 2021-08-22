// ********************************************************
// swap.cpp
// 功能：主函数调用swap函数置换两变量的值
// ********************************************************
#include <iostream>
using namespace std;
void swap( int&,  int& );
int main()
{
   int v1, v2;
   cout << "Please 2 values for the 2 variables: " ;
   cin  >> v1 >> v2;
   swap( v1, v2 );
   cout << "The 2 variables after swapping are " 
         << v1 << " and "<< v2 << endl;
   return 0;
}
void  swap( int&   firstInt,  int&   secondInt )   
{
	int  temporaryInt ; 
    temporaryInt = firstInt ;
    firstInt = secondInt ; 
    secondInt = temporaryInt ; 
}
