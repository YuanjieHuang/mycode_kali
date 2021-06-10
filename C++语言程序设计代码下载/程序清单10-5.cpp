程序清单11-1
// ***************************************************************
// dynamicBindingDemo.cpp
// 功能：演示虚函数的动态绑定
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
	void showName( ) // 继承成员的重定义
	{ 
		cout << "The first derived class" << endl;
	}
};

class DClass2: public Base {
public:  	
	void showName( ) // 继承成员的重定义
	{ 
		cout << "The second derived class" << endl;
	}
};

void main( )
{	
	Base bObj;		
    	DClass1 d1Obj;		
    	DClass2 d2Obj;
	Base *ptr;			// 定义指向基类的指针
	ptr = &bObj;	
	ptr -> showName();
	ptr = &d1Obj;		// 基类指针指向派生类对象
	ptr -> showName();    	   
	ptr = &d2Obj;		// 基类指针指向派生类对象
	ptr -> showName();           
}
