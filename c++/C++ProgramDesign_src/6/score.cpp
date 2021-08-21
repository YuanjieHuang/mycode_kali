// *************************************************************
// score.cpp
// 求从键盘输入的20个成绩（分数）中的最高分，
// 演示数组作函数参数的基本机制
// *************************************************************
#include <iomanip>
#include <iostream>
using  namespace  std ;
void  input ( float[ ], int ) ; 	                          
void  getHighest ( float[ ],  int , float& ) ;
const int NUM = 20;
int main (   )
{
     float score[NUM] ;	// 声明一维数组score，以存放20个成绩
     float highest ;
     // 通过score传递数组首地址、通过NUM传递数组长度给input函数的相应形参
     input( score, NUM ) ;    
     getHighest( score, NUM, highest ) ;
     cout  <<  "Highest is:  "  << highest  << endl ;
     return 0 ;
}
void input (  /* out */  float  array[ ], /* in */  int  number  )
// 输入number个学生成绩，存放在数组array中
// 前置条件：
//     array已分配内存，且足以存放个元素；number > 0
// 后置条件：
//     array[ 0..number -1 ]获得用户从键盘输入的值
{
	int  m;
	cout << "Please enter " << number << " scores." << endl;
	for ( m = 0 ; m < number;  m++ ) {
        cout << "Enter a Score(" << m+1 << "): " ;
        cin >>  array[m] ;
    }
}
void  getHighest (  /* in */  float   array[ ] ,
                       /* in */  int     number ,
                       /* out */  float& largest )	
// 获取数组array中的最大值
// 前置条件：
//     number > 0且array [0..number -1 ]已赋值
// 后置条件：
//     largest==array[0..number-1]中的最大值
{
    int  m;
    largest = array[0] ;     
    for ( m = 0 ; m < number;  m++ ) {   
        if ( array[m]  > largest )
            largest  =  array[m] ;
    }
}
