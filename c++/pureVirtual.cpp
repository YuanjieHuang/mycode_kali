#include <iostream>
using namespace std;
class A{
public:
virtual ~A(){}
virtual void f() = 0;
};
void A::f(){cout << "pure virtual" << endl;} //纯虚函数必须定义在类声明的外部
class D : public A{
public:
virtual void f(){ A::f(); }
//纯虚函数必须经由派生类显式的要求调用
};
int main() {
D d;
d.f();
return 0;
}