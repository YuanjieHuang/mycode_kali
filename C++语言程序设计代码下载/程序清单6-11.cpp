程序清单6-11
// ********************************************************
// pointer2.cpp
// 说明指针变量作函数参数
// ********************************************************

#include < iostream >
using namespace std;

void swap( int *p1, int *p2 )	// ④
{
    int temp;
	
    temp = *p1;	// ⑤
    *p1 = *p2;	// ⑥
    *p2 = temp;	// ⑦
}

int main()
{
    int a = 4, b = 5;
    int *p1, *p2;

    p1 = &a;	// ①
    p2 = &b;	// ②

    swap( p1, p2 );	// ③

    cout << "a = " << a << "  "<< "b = " << b << endl; // ⑧

    return 0;
}
