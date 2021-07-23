// **********************************************************
// pointerArray4.cpp
// 功能：用以说明用指针引用数组元素
// **********************************************************
#include < iostream >
using namespace std;
int main()
{
	float *p, score[5];
	int i;
	for( p = score; p < score+5; p++ )	// ①
		cin >> *p;
	for( i = 0; i < 4; i++, p++ )	// ②
		cout << *p << "  ";
    return 0;
}
