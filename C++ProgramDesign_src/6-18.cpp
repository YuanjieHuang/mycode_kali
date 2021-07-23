// ********************************************************
// scoreRevised.cpp
// 功能：介绍数组作函数参数的基本机制
// ********************************************************
#include <iomanip>
#include <iostream>
using  namespace  std ;
void  input ( float*, int ) ; 	                          
void  getHighest ( float*,  int , float& ) ;
const int NUM = 20;
int main (   )
{
    float score[NUM] ;	 // 声明一维数组score，以存储NUM个成绩
    float highest ;
    input( score, NUM ) ;    
    getHighest( score, NUM, highest ) ;
    cout << "Highest is:  " << highest << endl ;
    return 0;
}
void input (  float* array, int  number  )	
{
    int m;
for (  m=0 ; m < number;  m++, array++ ) {
         cout << "Enter a Score : " ;
         cin >> *array ;
    }
}
void  getHighest (  float* array, int number, float& largest )
{
int  m;
largest = *array;     
    for ( m = 0 ; m < number;  m++, array++ ) {   
         if ( *array  > largest )
              largest = *array ;
    }
}
