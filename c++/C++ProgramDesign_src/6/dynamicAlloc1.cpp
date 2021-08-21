// ********************************************************
// dynamicAlloc1.cpp
// 功能：介绍利用malloc和free进行动态内存分配和释放
// ********************************************************
#include <iostream>
using namespace std;
void inv( int* , int  );
int main()
{
    int *p;
    int length, i;
    cout << "Enter the length you want: ";
    cin >> length;
    p = ( int* )malloc( sizeof( int ) * length );	// ①
    cout << "Enter " << length << " integers:" << endl;
    for( i = 0 ; i < length; i++ )
        cin >> *(p+i);
    inv( p , length );	// 逆转元素的排列顺序
    cout << "The inversed integers:" << endl;
    for( i = 0 ; i < length; i++ )
        cout << *(p+i) << " ";
    cout << endl;
    free( p );		// ②
    return 0;
}
void inv( int* x, int n )
{
    int tmp,i,j;
    int m = ( n-1 )/2;
    for( i = 0; i <= m; i++ ) {
        j = n - 1 - i;
        tmp = x[i];
        x[i]= x[j];
        x[j]= tmp;
    }
}
