#include <iostream>
#include <type_traits>
 /*
 当一个数据类型满足了trival(平凡)和 standard_layout(标准布局)，我们则认为它是一个POD数据。可以通过std::is_pod来判断一个类型是否为POD类型。
 
 C ++中的普通旧数据结构是一个聚合类，它只包含PDS作为成员，没有用户定义的析构函数，没有用户定义的复制赋值运算符，也没有指向成员类型的非静态成员。
 */
struct A { int i; };            // C类型的结构体 ，是POD
class B : public A {};          // 是POD，没有数据成员 
struct C : B { void fn(){} };   // 是POD，有成员函数
struct D : C { D(){} };         // 不是POD ，有默认的构造函数
 
int main() 
{
	std::cout << "int: " << std::is_pod<int>::value << std::endl;
	std::cout << "A: " << std::is_pod<A>::value << std::endl;
	std::cout << "B: " << std::is_pod<B>::value << std::endl;
	std::cout << "C: " << std::is_pod<C>::value << std::endl;
	std::cout << "D: " << std::is_pod<D>::value << std::endl;
	return 0;
}