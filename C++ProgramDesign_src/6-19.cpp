// ********************************************************
// decSort.cpp
// 功能：对一维数组中的元素进行降序排序
// ********************************************************
#include <iostream>
using namespace std;
const int NUM = 5;
void sort( int* , int  );
int main()
{
    int *p, a[NUM];
    cout << "Enter " << NUM << " integers:" << endl;
    for( p = a; p < a + NUM;  p++ )
          cin >> *p;
    sort( a, NUM );
    cout << "The sorted result:" << endl;
    for( p = a; p < a + NUM;  p++ )
          cout << *p << " ";
    cout << endl;
    return 0;
}
void sort( int* x, int n )
{
    int i,j,k,t;
    for( i = 0; i < n - 1; i++ ) {	// ①
    // 找到[i..n-1]之间的最大元素，用k记录其下标
        k = i;
        for( j = i + 1; j < n; j++ ) {	// ②
            if( *(x+j) > *(x+k) ) 
                 k = j;
        }
        if( k != i ) {	// 若k != i，则交换k、i两个元素
            t = x[i];
            x[i] = x[k];
            x[k] = t;
        }
    }
}
