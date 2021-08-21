// ********************************************************
// dynamicAlloc2.cpp
// 功能：介绍利用new和delete进行动态内存分配和释放
// ********************************************************
#include <iostream>
using namespace std;
void inv( int* , int  );
int main()
{
    int *p;
    int length, i;
    cout << "Enter the lenght you want: ";
    cin >> length;
    p = new int[ length ];	// ①
    cout << "Enter " << length << " integers:" << endl;
    for( i = 0 ; i < length; i++ )
        cin >> *(p+i);
    inv( p , length );
    cout << "The inversed integers:" << endl;
    for( i = 0 ; i < length; i++ )
        cout << *(p+i) << " ";
    cout << endl;
    delete []p;		// ②
    return 0;
}
/*函数inv的代码同dynamicAlloc1.cpp，此处略*/
