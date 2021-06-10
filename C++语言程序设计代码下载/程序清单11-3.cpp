程序清单11-3
// ***************************************************************
// nonVirtualDestructor.cpp
// 功能：演示非虚析构函数的调用
// ***************************************************************

#include <iostream>
using namespace std;

class Base {
public:	
	~Base( ) 
	{ 
		cout << "Base destructor" << endl;
	}
};

class DClass: public Base {
public:  	
	~DClass( ) 			// 继承成员的重定义
	{ 
		cout << "Derived class destructor" << endl;
	}
};

void main( )
{	
	Base *ptr;			// 定义指向基类的指针
	ptr = new DClass;	// 动态创建派生类对象
	... // 省略对ptr的使用
	delete ptr;			// 动态撤销派生类对象
}
