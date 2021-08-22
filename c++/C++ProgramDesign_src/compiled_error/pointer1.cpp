// *********************************************************
// pointer1.cpp
// 修改指针变量使之指向另一个变量
// *********************************************************
#include <iostream>
using namespace std;

void swap( int *p1, int *p2 )
{
    int *p;
    p = p1;
    p1 = p2;
    p2 = p;
}
int testSwap()
{
    int a = 4, b = 5;
    int *p1, *p2;
    p1 = &a;
    p2 = &b;
    if(a < b) swap( p1, p2 );
    cout << "max = " << *p1 << "  "<< "min = " << *p2;
    return 0;
}

int swap_and_test()
{
int a = 4, b = 5;	// ①
    int *p1, *p2, *p;	// ②
    p1 = &a;	// ③ p1指向a
    p2 = &b;	// ④ p2指向b
    p = p1;	// ⑤ p1与p2的值互换，因此p1指向b，p2指向a
    p1 = p2;	// ⑥
    p2 = p;	// ⑦
    cout << "a = " << a << "  " << "b = " << b << endl;	// ⑧
    cout << "p1指向的变量的值：" << *p1 << "  "<< endl;	// ⑨
    cout << "p2指向的变量的值：" << *p2 << endl;	// ⑩
    return 0;
}

// ********************************************************
// 说明指针变量作函数参数
// ********************************************************
void swap1( int *p1, int *p2 )	// ④
{
    int temp;
    temp = *p1;	// ⑤
    *p1 = *p2;	// ⑥
    *p2 = temp;	// ⑦
}
int testSwap1()
{
    int a = 4, b = 5;
    int *p1, *p2;
    p1 = &a;	// ①
    p2 = &b;	// ②
    swap1( p1, p2 );	// ③
    cout << "a = " << a << "  "<< "b = " << b << endl; // ⑧
    return 0;
}

// **********************************************************
// 功能：用以说明通过指针引用数组元素
// **********************************************************
int accessArrayElemByPointer1()
{
    float score[5] = { 50, 60, 70, 80,90 };
    int i;
    for( i = 0; i < 5; i++ ) { // ①
        cout << score[i] << "   ";
    }
    cout << endl;
    for( i = 0; i < 5; i++ ) { // ②
        cout << *(score+i) << "   ";
    }
    return 0;
}

// 功能：用以说明通过指针变量引用数组元素
// **********************************************************
int accessArrayElemByPointer2()
{
    float score[5] = { 50, 60, 70, 80, 90 };
    float* p = score;
    int i;
    for( i = 0; i < 5; i++ ) { // ①
        cout << p[i] << "  ";
    }
    cout << endl;
    for( i = 0; i < 5; i++ ) { // ②
        cout << *(p+i) << "  ";
    }
    return 0;
}

// ************************************************************
// 功能：用以说明通过指针变量自增引用数组元素
// ************************************************************
int accessArrayElemByPointer3()
{
	float score[5] = { 50, 60, 70, 80,90 };
	float* p;
	for( p = score; p < score+5; p++ ) // ①
		cout << *p << "  ";
	return 0;
}

// **********************************************************
// 功能：用以说明用指针引用数组元素
// **********************************************************
int accessArrayElemByPointer4()
{
	float *p, score[5];
	int i;
	for( p = score; p < score+5; p++ )	// ①
		cin >> *p;
	for( i = 0; i < 4; i++, p++ )	// ②
		cout << *p << "  ";
    return 0;
}

