/*前向引用声明
类先声明后使用
在声明前引用需要前向引用声明
前向引用声明只是引入标识符，可以具体声明在其它地方

class B;    //前向引用声明
class A{
public:
	void f(B b);
};
class B{
public:
	void g(A a);
};

不能再内联函数中使用这样的对象
只能使用被声明的符号，儿不能涉及类的任何细节

eg：错误
class Fred;
class Barney{
	Fred x;   //错误：类Fred的声明尚部完善
};
class Fred{
	Barney y;
};

软件工程UML语言：
事物；关系；图


*/
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



对象指针
·对象指针定义形式
	  类名 *对象指针名;
	  例:Point a(5，10);
				Piont *ptr;
				ptr=&a;
·通过指针访问对象成员
	  对象指针名一>成员名
	  例：ptr->getx()相当于(*ptr).getx();

this指针：
·隐含于类的每一个非静态成员函数中。
·指向成员函数所操作的对象。
  ·当通过一个对象调用成员函数时，系统先将该对象的地址赋与this指针，然后
	调用成员函数，成员函数对对象的数据成员进行操作时，就隐含使用了this指针。
·例如:Point类的getX函数中的语句:
  return x;
  相当于:
  return this->x;

  错误实例：
  class Fred;//前向引用声明
  class Barney{
  Fred x;//错误:类Fred的声明尚不完善      Fred *x;正确：可以用new动态分配内存
  };
  class Fred{
  Barney y;
  };



  /*
类的定义：
class 类名称
{
public：
	公有成员（外部接口）   //公有数据和函数 
private：
	私有成员                //只允许类内访问 ，最开头声明可以省略关键字 
protected：
	保护成员	 			// 
}；
类内的初始化：
class Clock{
public:void setTime(int newH,int newM,int newS);
		void showTime();
private:
	int hour = 0,minute = 0,second = 0;    //类内初始化 
}; 

内联函数：
构造函数：
	1.Clock myClock(0,0,0)
默认构造函数：
	Clock(); 
	即：
	Clock::Clock():hour(0),minute(0),second(0){};
	主函数中：
	int main(){
		Clock c1(8,9,0);  //调用有参数的构造函数
		Clock c2;      //调用没有参数的构造函数(默认构造函数)
		..... 
}
隐含生成的构造函数：
class Clock{
public:
	Clock()=default;    //指示编译器提供默认构造函数
	Clock(int newH,int newM, int newS);      //构造函数 
private:
	int hour = 0,minute = 0,second = 0;    //类内初始化 
};  

//构造函数：
class Clock{
public:
	Clock(int newH,int newM, int newS);      //构造函数 
	void setTime(int newH,int newM,int newS);
	void showTime();
private:
	int hour,minute,second;    //类内初始化 
};  
 构造函数的实现：
 Clock::Clock(int newH,int newM,int newS):
 hour(newH),minute(newM),second(newS){
}   //newH赋值给hour，后面类似（效率高一点）


委托构造函数
//Clock(int newH,int newM,int newS):hour(newH),minute(newM),second(newS){}
Clock():Clock(0,0,0){}

复制构造函数:
//class 类名{
public:
类名(形参)；   //构造函数
类名（const 类名 &对象名）；    //复制构造函数  const保证不改变实参的值，只读不写 
//... 
} ;
类名::类(const 类名 &对象名）   //复制构造函数的实现
{函数体} 
复制函数被调用的三种情况
1.初始化
2.如果函数的形参是类的对象，调用函数时，将使用实参对象初始化形参对象，发生复制构造
3.如果函数的返回值时类的对象，函数执行完成返回主函数时，将使用return语句中的类的对象初始化一个临时无名对象，传递给主调函数，发生复制函数
指示编译器不生成默认复制构造函数：：Point（const Point&p)=delete;
class Point{//类的定义
public:
	Point(int xx=0,int yy=0){x=xx,y=yy;}  //构造函数，内联
	Point(const Point&p)=delete;   //指示编译器不生成默认的复制构造函数
private:
	int x,y;   //私有数据
	}； 
 
*/ 