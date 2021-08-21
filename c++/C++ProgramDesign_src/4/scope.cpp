// ********************************************************
// scope.cpp
// 功能：演示各类全局标识符、局部标识符的作用域
// ********************************************************
#include <iostream>
using namespace std;
void block1( int, char );
void block2();
int a1;
char a2;
int main()
{
	a1 = 0; 	// 使用全局变量a1
	a2 = 'A'; 	// 使用全局变量a2
	// 输出全局变量a1和a2
	cout << "Global a1 and a2 in main are: " << a1 << ' ' << a2 << endl << endl;
	block1( 3, a2 );   // 使用全局变量a2
	block2();
	return 0;
}
void block1( int a1, char b2 )   // block1中的局部变量a1和b2
{
	int c1;  // block1的局部变量
	int d2;  // block1的局部变量
	// block1中的局部变量b2
	cout << "b2 in Block1 is: " << b2 << endl;  
	// block1中的局部变量a1,而非全局变量a1
	cout << "a1 in Block1 is: " << a1 << endl;  
	// block1中的局部变量c1和d2,未经赋值
	cout << "c1 in Block1 is: " << c1 << endl;  
	cout << "d2 in Block1 is: " << d2 << endl;  
}
void block2()
{
	int a1;  // block2的局部变量
	int b2;  // block2的局部变量
     // block2的局部变量a1，而非全局变量a1，也不是Block1中的a1
	a1 = 1;  
	b2 = 1;  // block2的局部变量b2
	cout << "b2 in Block2 is: " << b2 << endl << endl;
	while( a1 <= 3 )  // block3
	{
		int b2;	// block3的局部变量
		b2 = 2;	// block3的局部变量b2，而非block2的局部变量b2
		b2++;	// block3的局部变量b2，而非block2的局部变量b2
		// block3的局部变量b2，而非block2的局部变量b2
		cout << "b2 in Block3 is:" << b2 << endl;  
		a1++;	// block2的局部变量a1
	}
	// block2的局部变量b2,而非block3的局部变量b2
	cout << endl << "b2 in Block2 is:" << b2 << endl;  
}
