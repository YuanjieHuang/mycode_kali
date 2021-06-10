程序清单6-8
// ********************************************************
// avgTemp2.cpp
// 求各地12个月中最高的月平均温度；利用typedef定义数组类型
// ********************************************************

#include <iostream>
using  namespace  std ;

const int PLACES_NUM = 2;
const int MONTHS_NUM = 3;

typedef float Array2D[PLACES_NUM][MONTHS_NUM];	// ①
typedef float Array1D[PLACES_NUM];	// ②

void input ( Array2D );
void getHighest ( Array2D, Array1D );

int main (   )
{
    Array2D avgTemp;
    Array1D highest;        
    int m;

    input( avgTemp ) ;	// ③
    getHighest( avgTemp, highest ) ;	// ④
           
    cout <<  "Highest temperatures for " << PLACES_NUM << " citys were:" << endl;
    for( m = 0; m < PLACES_NUM; m++ )
	   cout  << highest[m]  << endl ;
     
    return 0 ;
}

void input ( Array2D array )	// ⑤
{
    int  m, n;

    for ( m = 0 ; m < PLACES_NUM;  m++ ) {
       for( n = 0; n < MONTHS_NUM; n++ ) {
          cout << "Enter a value for [" << m << "][" << n << "]: ";
          cin >>  array[m][n] ;
       }
}
}

void  getHighest ( Array2D array , Array1D largest )	// ⑥
{
    int  m, n;
          
	for ( m = 0 ; m < PLACES_NUM;  m++ ) {   
        largest[ m ] = array[ m ][ 0 ];
        for( n = 0; n < MONTHS_NUM; n++ ) {
		if ( array[m][n]  > largest[m] )
			largest[m]  =  array[m][n];
        }
    }
}
