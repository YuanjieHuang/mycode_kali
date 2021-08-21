// ***********************************************************
// avgTemp.cpp
// 求各地12个月中最高的月平均温度；介绍二维数组作函数参数的基本机制
// ***********************************************************
#include <iostream>
using  namespace  std ;
const int PLACES_NUM = 9;
const int MONTHS_NUM = 12;
void  input ( float[ ][MONTHS_NUM], int ) ; 	                          
void  getHighest ( float[ ][MONTHS_NUM],  int , float[] ) ;
int main (   )
{
    float avgTemp[PLACES_NUM][MONTHS_NUM]; 	   
    float highest[PLACES_NUM];	// 用于存储各地的最高月平均温度
    int m;
    input( avgTemp, PLACES_NUM ) ;	// ①
    getHighest( avgTemp, PLACES_NUM, highest ) ;	// ②
    cout <<  "Highest temperatures for " << PLACES_NUM << " citys were:" << endl;
    for( m = 0; m < PLACES_NUM; m++ )
          cout  << highest[m]  << endl ;
    return 0 ;
}
void input (  /*out*/  float  array[ ][MONTHS_NUM], /*in*/   int row ) // ③
// 输入各地各月的平均温度
{
    int  m, n;
    for ( m = 0 ; m < row;  m++ ) {
		for( n = 0; n < MONTHS_NUM; n++ ) {
             cout << "Enter a value for [" << m << "][" << n << "]: ";
             cin >>  array[m][n] ;
		}
    }
}
void getHighest (	/* in */	float   array[ ][MONTHS_NUM] ,
	/* in */	int     row ,
	/* out */	float   largest[] )	// ④
// 获取二维数组array中每一行的最大值
{
	int  m, n;
	for ( m = 0 ; m < row;  m++ ) {   
          largest[ m ] = array[ m ][ 0 ];
          for( n = 0; n < MONTHS_NUM; n++ ) {
			if ( array[m][n]  > largest[m] )
			    largest[m]  =  array[m][n];
		}
    }
}
