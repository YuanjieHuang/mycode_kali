/*
多文件结构和编译预处理命令
一个工程可以划分为多个源文件，例如：
	类声明文件（.h文件）
	类实现文件（.cpp文件）
	类的使用文件（.main（）所在的.cpp文件）
利用工程来组合各个文件

class Point	//Point类定义
{
public:	//外部接口
	Point(int xx=0, int yy=0) {X=xx;Y=yy;countP++;}	//构造函数
	Point(Point &p);	//拷贝构造函数
	~Point(){  countP--; }
	int GetX() {return X;}
	int GetY() {return Y;}
	static void GetC() {cout<<" Object id="<<countP<<endl;}
	//静态函数成员
private:	//私有数据成员
	int X,Y;
	static int countP;	//静态数据成员引用性说明
};

#include "pch.h"
#include"Point.h"	//自己写的头文件是带h的
#include <iostream>
using namespace std;

int Point::countP=0;	//使用类名初始化静态数据成员定义性说明

Point::Point(Point &p)
{
	X=p.X;
	Y=p.Y;
	countP++;
}

void GetC() {cout<<" Object id="<<countP<<endl;}

文件3，主函数
#include "pch.h"
#include"Point.h"	//自己写的头文件是带h的
#include <iostream>
using namespace std;

void main()	//主函数实现
{
	Point A(4,5);	//定义对象A，其构造函数使得countP+1
	cout<<"Point A,"<<A.GetX()<<","<<A.GetY();
	A.GetC();	//输出对象号，对象名引用
	Point B(A);	//定义对象B
	cout<<"Point B,"<<B.GetX()<<","<<B.GetY();
	Point::GetC();	//输出对象号，类名引用
}

外部函数：
	在所有类之外声明的函数（也就是非成员函数），都是具有文件作用域的。
	这样的函数都可以在不同的编译单元中被调用
	只要在调用之前进行引用性声明（即声明函数原型）即可。
将变量和函数限制在编译单元内：
	在匿名命名空间中定义变量和函数，都不会暴露给其它的编译单元。
	namespace{//匿名命名空间
		int n;
		void f(){
			n++;
		}
	}

·标准C++类库是一个极为灵活并可扩展的可重用软件模块的集合。标准C++
  类与组件在逻辑上分为6种类型:
  ·输入/输出类
  ·容器类与抽象数据类型	//处理大批量的数据，类模板的总称
  ·存储管理类
  ·算法
  ·错误处理
  ·运行环境支持

  ·#include包含指令
  ·将一个源文件嵌入到当前源文件中该点处。
  ·#include<文件名>
	·按标准方式搜索，文件位于c++系统目录的include子目录下
  口#include”文件名”
	·首先在当前目录中搜索，若没有，再按标准方式搜索。
·#define宏定义指令
  ·定义符号常量;很多情况下已被const定义语句取代。
  ·定义带参数宏，已被内联函数取代。
·#undef
·删除由#define定义的宏;使之不再起作用。

条件编译指令——#if #endif:
		#if 常量表达式
		 //当“常量表达式“非零时编译
			程序正文
			#endif
			......
条件编译指令一#else
#if常量表达式
	//当”常量表达式“非零时编译
		程序正文1
#else
  //当"常量表达式"为零时编译
		程序正文2
#endlf


条件编译指令(续)
}#ifdef 标识符
	程序段1
#e1se
	程序段2
#endif
·如果"标识符"经#defined定义过,且未经undef删除,则编译程序段1;
  否则编译程序段2。

  条件编译指令(续)
#ifndef 标识符
	程序段1
#endif
如果"标识符"未被定义过,则编译程序段1;
否则编译程序段2。

*/
#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 
}


