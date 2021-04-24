/*
枚举类定义
1.语法形式
enum class 枚举类型名：底层类型 {枚举值列表};
2.例如
	enum class Typle {General,Light,Midium,Heeavy};		//都是int型
	enum class Typle:char {General,Light,Midium,Heeavy};		//都是char型
	enum class Category{General=1,Pistol,MachineGun,Cannon};	//后面的枚举依次增加

枚举类的优势：
1.强作用域，其作用域限制在枚举类中
	使用Type类型的枚举值General：
		Type：：General
2.转换限制，枚举类对象不可以与整型隐式相互转换

3.可以指定底层类型
	enum class Type：char {General,Light,Medium,Heavy};

*/

#include <iostream>
using namespace std;
// 在C++11新标准中推出了一种新的枚举定义办法叫做枚举类，也称作强类型枚举。
// enum class 枚举类型名: 底层类型 {枚举值列表};
enum class Side{Right,Left};
enum class Thing{wrong,Right};	//不冲突,在一般类里面相同的名字会发生冲突

int main()
{

    //std::cout << "Hello World!\n"; 
	Side s = Side::Right;
	Thing w = Thing::wrong;//使用Type的枚举值wrong：
	cout << (s == w) << endl;  //编译错误，无法直接比较不同的枚举类
	return 0;	
}

