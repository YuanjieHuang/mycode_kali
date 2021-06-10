程序清单12-6
// ***************************************************************
// auto_ptrDemo.cpp
// 功能： 演示标准库中auto_ptr类的使用
// ***************************************************************

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class DemoClass {
public:
	DemoClass(const string objname) : name(objname)
	{ 
		cout << "construcing DemoClass object..." << endl;
	}

	~DemoClass()
	{
		cout << "destructing DemoClass object: " << name << endl;
	}

	string who()
	{
		return name;
	}

private:
	string name;
};

void f()
{
	// 创建一个auto_ptr对象，用该对象指向一个动态创建的DemoClass对象
	auto_ptr<DemoClass> dcPtr1(new DemoClass("dcobj"));

	cout << "name of the DemoClass object constucted: " << dcPtr1->who() << endl;

	// 创建另一个auto_ptr对象，将dcPtr1复制给该对象
	auto_ptr<DemoClass> dcPtr2(dcPtr1);

	cout << "name of the DemoClass object to which dcPtr2 points: "
		 << (*dcPtr2).who() << endl;

	throw 8;		// 抛出一个int型异常
}

int main()
{
	
	try {
		f();		// 调用有可能产生异常的函数f
	}
	catch (int) {	// 捕获int型异常
		cout << "an int exception occurred!" << endl;
	}

	cout << "end of main" << endl;

	return 0;
}
