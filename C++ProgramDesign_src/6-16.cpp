// ************************************************************
// pointerArray3.cpp
// 功能：用以说明通过指针变量自增引用数组元素
// ************************************************************
#include < iostream >
using namespace std;
int main()
{
	float score[5] = { 50, 60, 70, 80,90 };
	float* p;
	for( p = score; p < score+5; p++ ) // ①
		cout << *p << "  ";
	return 0;
}
