程序清单6-10
// *********************************************************
// pointer1.cpp
// 修改指针变量使之指向另一个变量
// *********************************************************

#include < iostream >
using namespace std;

int main()
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
