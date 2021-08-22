#include <iostream>
#include<type_traits>
using namespace std;
 
//空类是平凡的
//以下是平凡的
class Trival1 {};  
 
 
struct Trival1_1{int x;double y;};
 
class Trival1_2{
public:
	int x;
private:
	int y;
};
 
 
///以下是no-trival,不是POD类型
//非平凡的构造函数
class Trival2 { Trival2(){} };
 
//非平凡的拷贝构造函数
class Trival3 { Trival3(Trival3&){} };
 
//非平凡的拷贝赋值运算符
class Trival4 { Trival4 operator=(Trival4&){} };
 
//非平凡的移动赋值运算符
class Trival5 { Trival5 operator=(Trival5&&){} };
 
//非平凡的析构函数
class Trival6 { ~Trival6(){} };
 
//有虚函数---不是trival,不是POD
class Trival7 { virtual void foo() = 0; };
 
//有虚基类 --- 不是trival,不是POD
class Trival8 : Trival7 {};
 
 
int main()
{
	//基本数据类型是平凡的（trival）,也就是POD的
	cout << std::is_trivial<int>::value       << endl;  
	cout << std::is_trivial<Trival1>::value   << endl;  
	cout << std::is_trivial<Trival1_1>::value << endl;  
	cout << std::is_trivial<Trival1_2>::value << endl; 
     
	cout << std::is_trivial<Trival2>::value   << endl;  
	cout << std::is_trivial<Trival3>::value   << endl;  
	cout << std::is_trivial<Trival4>::value   << endl;  
	cout << std::is_trivial<Trival5>::value   << endl;  
	cout << std::is_trivial<Trival6>::value   << endl;  
	cout << std::is_trivial<Trival7>::value   << endl;  
	cout << std::is_trivial<Trival8>::value   << endl;  
 
	return 0;
}