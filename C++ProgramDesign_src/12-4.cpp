// ***************************************************************
// ObjDestructInStackUnwinding.cpp
// 功能： 演示栈展开过程中的对象撤销
// ***************************************************************
#include <iostream>
#include <string>
using namespace std;
class C {
public:
	C(const string objname) : name(objname)
	{ }
	~C()
	{
		cout << "destructing C object: " << name << endl;
	}
private:
	string name;
};
class D {
public:
	class Exception { };
	D() 
	{
		cout << "constructing D object" << endl;
		throw Exception();
	}
	~D()
	{
		cout << "destructing D object: " << endl;
	}
};
void f2()
{
	C obj1("obj1");	// 声明对象
	C obj2("obj2");	// 声明对象
	throw 8;    			// 抛出int型异常
}
void f1()
{
	try {
		f2();
	}
	catch (int) {  	// int型异常的处理代码
		cout << "An int exception occurred!" << endl;
	}
	try {
		D objd; 			// 声明对象
	}
	catch (float) {  	// float型异常的处理代码
		cout << "A float exception occurred!" << endl;
	}
}
int main()
{
	try {
		f1();
	}
	catch (D::Exception) {
		cout << "A D::Exception exception occurred!" << endl;
	}
	cout << "End of main" << endl;
	return 0;
}
