程序清单11-2
// ***************************************************************
// dynamicBindingByRef.cpp
// 功能：演示通过基类引用实现动态绑定
// ***************************************************************

#include <iostream>
using namespace std;

class Base {
public:	
	virtual void showName( ) 
	{ 
		cout << "Base class" << endl;
	}
};

class DClass1: public Base {
public:  	
	void showName( ) 	// 继承成员的重定义
	{ 
		cout << "The first derived class" << endl;
	}
};

class DClass2: public Base {
public:  	
	void showName( ) 	// 继承成员的重定义
	{ 
		cout << "The second derived class" << endl;
	}
};

void printIdentity(Base& obj)
{	
	obj.showName(); // 通过基类引用调用虚函数
}

void main( )
{	
	Base bObj;		
	DClass1 d1Obj;		
	DClass2 d2Obj;

	printIdentity(bObj);			
	printIdentity(d1Obj);
	printIdentity(d2Obj);
}
