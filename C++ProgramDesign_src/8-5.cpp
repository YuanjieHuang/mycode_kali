// ***************************************************************
// constructorAndDestructorInComposition.cpp
// 演示组合及派生关系中构造函数和析构函数的调用次序
// ***************************************************************
#include <iostream> 
using namespace std;
class C {
public:
	C() 		// 构造函数
	{	
		cout << "Constructing C object.\n";	
	}
	~C() 	// 析构函数
	{	
		cout << "Destructing C object.\n";	
	}
};
class Base {
public:	
	Base() 	// 构造函数
	{	
		cout << "Constructing Base  object.\n";	
	}
	~Base() 	// 析构函数
	{	
		cout << "Destructing Base  object.\n";	
	}
}; 
class Derived: public Base {
public:	
	Derived() 	// 构造函数
	{  
		cout << "Constructing derived object.\n";  
	}
	~Derived() 	// 析构函数
	{  
		cout << "Destructing derived object.\n";	
	}
private:
    C 	mObj; 	// 嵌入对象
}; 
int main()
{	
	Derived obj;	// 声明一个派生类的对象
 	// 什么也不做，仅完成对象obj的创建与撤销
	return 0;
} 
