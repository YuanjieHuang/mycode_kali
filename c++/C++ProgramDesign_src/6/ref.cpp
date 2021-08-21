// ********************************************************
// ref.cpp
// 采用引用参数交换两变量的值
// ********************************************************
#include < iostream >
using namespace std;
void swap( int& x, int& y ) 
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a = 4, b = 5;
    swap( a, b );
    cout << "a = " << a << "  "<< "b = " << b << endl; 
    return 0;
}
