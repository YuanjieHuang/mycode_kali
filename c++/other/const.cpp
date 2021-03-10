/*
除常成员函数都有可能修改对象的值
常类型：
常对象：常类型的对象必须进行初始化，而且不能被更新。
class A
{
	 public:
		 A(int i,int j) {x=i; y=j;}
					 ...
	 private:
		 int x,y;
};
A const a(3,4); //a是常对象，不能被更新

常成员：
常成员函数
例一：
#include<iostream>
using namespace std;
class R
{    public:
		 R(int r1, int r2){R1=r1;R2=r2;}
		 void print();
		 void print() const;		//常成员函数的声明
	  private:
		 int R1,R2;
};
void R::print()
{     cout<<R1<<":"<<R2<<endl;
}
void R::print() const		//承诺绝不改变对象的状态
{     cout<<R1<<";"<<R2<<endl;
}
void main()
{   R a(5,4);
	 a.print();  //调用void print()	//还可以调用类中的常函数；即普通函数是可以调用常函数的
	 const R b(20,52);
	 b.print();  //调用void print() const
}


例二：
#include<iostream>
using namespace std;
class A
{public:
	A(int i);
	void print();
	const int& r;
private:
	const int a;
	static const int b;   //静态常数据成员
};
const int A::b=10;
A::A(int i):a(i),r(a) {}	//常成员a不能放在函数体中赋值；必须在初始化列表中进行初始化
void A::print()
{    cout<<a<<":"<<b<<":"<<r<<endl; }
void main()
{//建立对象a和b，并以100和0作为初值，分别调用构造函数，通过构造函数的初始化列表给对象的常数据成员赋初值
A a1(100), a2(0);
a1.print();
a2.print();
}

使用const关键字说明的函数。
常成员函数不更新对象的数据成员。
常成员函数说明格式：类型说明符  函数名（参数表）const;这里，const是函数类型的一个组成部分，因此在实现部分也要带const关键字。
const关键字可以被用于参与对重载函数的区分
通过常对象只能调用它的常成员函数。
常数据成员
使用const说明的数据成员。

常引用：被引用的对象不能被更新。
	const  类型说明符  &引用名
	友元函数中常引用做参数，技能获得较高的执行效率，又能保证实参的安全性
	例三：
#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;
class Point	//Point类定义
{
public:	//外部接口
	Point(int xx=0, int yy=0) {X=xx;Y=yy;}
	int GetX() {return X;}
	int GetY() {return Y;}
	friend float fDist(const Point &a, const Point &b);	//友元函数声明;const使得函数为只读
private:	//私有数据成员
	int X,Y;
};
float fDist(const Point &p1,const Point &p2)	//友元函数实现；const使得函数为只读
{	double x=double(p1.X-p2.X);	//通过对象访问私有数据成员
	double y=double(p1.Y-p2.Y);
	return float(sqrt(x*x+y*y));
	return static_cast<float>(sqrt(x*x+y*y));
}
void main()	//主函数
{
	Point myp1(1,1),myp2(4,5);	//定义Point类的对象
	cout<<"The distance is:";
	cout<<fDist(myp1,myp2)<<endl;	//计算两点间的距离
}
常对象：必须进行初始化,不能被更新。
	类名  const  对象名
常数组：数组元素不能被更新(下一章介绍)。
类型说明符  const  数组名[大小]...
常指针：指向常量的指针(下一章介绍)。

*/

/*
#include "pch.h"
#include<iostream>
using namespace std;
class A
{
public:
	A(int i);
	void print();
	const int& r;
private:
	const int a;
	static const int b;   //静态常数据成员
};
const int A::b = 10;
A::A(int i) :a(i), r(a) {}	//r是取值a
void A::print()
{
	cout << a << ":" << b << ":" << r << endl;
}
void main()
{//建立对象a和b，并以100和0作为初值，分别调用构造函数，通过构造函数的初始化列表给对象的常数据成员赋初值
	A a1(100), a2(0);
	a1.print();
	a2.print();
}
*/

#include <iostream>
#include <cmath>
using namespace std;
class Point	//Point类定义
{
public:	//外部接口
	Point(int xx = 0, int yy = 0) { X = xx; Y = yy; }
	int GetX() { return X; }
	int GetY() { return Y; }
	friend float fDist(const Point &a, const Point &b);	//友元函数声明;const使得函数为只读
private:	//私有数据成员
	int X, Y;
};
float fDist(const Point &p1, const Point &p2)	//友元函数实现；const使得函数为只读
{
	double x = double(p1.X - p2.X);	//通过对象访问私有数据成员
	double y = double(p1.Y - p2.Y);
	return float(sqrt(x*x + y * y));
	//return static_cast<float>(sqrt(x*x + y * y));		//与return float(sqrt(x*x + y * y));作用一样
}
void main()	//主函数
{
	Point myp1(1, 1), myp2(4, 5);	//定义Point类的对象
	cout << "The distance is:";
	cout << fDist(myp1, myp2) << endl;	//计算两点间的距离
}

