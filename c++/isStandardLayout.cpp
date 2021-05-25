#include <iostream>
#include<type_traits> //C++11中
 
//成员a和b具有不同的访问权限,不符合标准布局
class A 
{ 
private:
	int a;
public:
	int b;
};
 
class B1
{
	static int x1;
};
 
class B2
{
	int x2;
};
 
//子类含有非静态数据成员，
//基类有1个非静态数据成员，不符合标准布局
class B_1 : B1, B2
{
	int x;
};
 
//子类含有静态数据成员，
//基类有1个非静态数据成员，符合标准布局
class B_2 : B1,B2
{
	static int x;
};
 
//第一个非静态成员是基类类型,不符合标准布局
class C1 {};
class C_1 : C1
{
	C1 c;
};
 
//第一个是静态数据成员的基类类型，符合标准布局
class C_2 : C1
{
	static int C1;
	int x;
};
 
//有虚函数,不符合标准布局
class D { virtual void foo() = 0; };
 
//有虚基类
class E : D {};
 
//非静态成员x不符合标准布局类型
class F { A x; };
 
int main()
{
	//基本数据类型符合标准布局
	std::cout << std::is_standard_layout<int>::value << std::endl;
	std::cout << std::is_standard_layout<A>::value << std::endl;  
	std::cout << std::is_standard_layout<B_1>::value << std::endl;  
	std::cout << std::is_standard_layout<B_2>::value << std::endl;  
	std::cout << std::is_standard_layout<C_1>::value << std::endl;  
	std::cout << std::is_standard_layout<C_2>::value << std::endl;
	std::cout << std::is_standard_layout<D>::value << std::endl;  
	std::cout << std::is_standard_layout<E>::value << std::endl;  
	std::cout << std::is_standard_layout<F>::value << std::endl;  
 
	return 0;
}