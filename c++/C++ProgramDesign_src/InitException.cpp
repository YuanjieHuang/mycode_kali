// ***************************************************************
// InitException.cpp 
// 功能：演示函数try块对创建子对象时所产生异常的处理
// ***************************************************************
#include <iostream>
using namespace std;
class Base {
public:
    class BaseException {};
    Base(int i) : data(i) 
	{
        throw BaseException(); 
	}
private:
    int data;
};
class Derived : public Base {
public:
     class DerivedException {
	public:
        DerivedException(const char* msg) : message(msg)
		{}
        const char* what() const 
		{ 
			return message; 
		}
	private:
        const char* message;
	};
     Derived(int j)
	try : Base(j) 
	{
        // 构造函数体
        cout << "Enter Base()" << endl;
	}
	catch(BaseException&) {
        throw DerivedException("Base subobject threw an exception");
	}
};
int main() 
{
    try {
        Derived dobj(100);
	}
	catch(Derived::DerivedException& de) {
        cout << de.what() << endl;  
	}
	return 0;
} 
