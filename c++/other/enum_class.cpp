// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
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

#include "pch.h"
#include <iostream>
using namespace std;

enum class Side{Right,Left};
enum class Thing{wrong,Right};	//不冲突,在一般类里面相同的名字会发生冲突

int main()
{

    //std::cout << "Hello World!\n"; 
	Side s = Side::Right;
	Thing w = Thing::wrong;
	cout << (s == w) << endl;  //编译错误，无法直接比较不同的枚举类
	return 0;	
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
