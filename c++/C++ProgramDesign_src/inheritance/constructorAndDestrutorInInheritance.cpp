// ***************************************************************
// constructorAndDestrutorInInheritance.cpp
// 演示多层次继承中构造函数和析构函数的调用次序
// ***************************************************************
#include <iostream> 
using namespace std;
class Base {
public:	
	Base() 			// 构造函数
	{	
		cout << "Constructing Base object.\n";	
	}
	~Base() 			// 析构函数
	{	
		cout << "Destructing Base object.\n";	
	}
};
class DerivedLevel1: public Base {
public:	
	DerivedLevel1() // 构造函数
	{
		cout << "Constructing derived_level_1 object.\n";
	}
	~DerivedLevel1() // 析构函数
	{  
		cout << "Destructing derived_level_1 object.\n";	
	}
}; 
class DerivedLevel2: public DerivedLevel1 {
public:	
	DerivedLevel2() // 构造函数
	{
		cout << "Constructing derived_level_2 object.\n";
	}
	~DerivedLevel2() // 析构函数
	{ 
		cout << "Destructing derived_level_2 object.\n";	
	}
}; 
int main()
{	
	DerivedLevel2  obj;	// 声明一个后代类的对象
 	// 什么也不做，仅完成对象obj的创建与撤销
	return 0;
} 
