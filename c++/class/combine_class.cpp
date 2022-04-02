#include <iostream>
#include <cmath>
using namespace std; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
类的组合（组合类）：一些类的对象可以用其它类（部件类）来表示 
组合类没有权力，访问类内部的私有成员； 
原则：数据初始，对象成员初始化

初始化次序：
1.先定义先初始化
2.构造函数调用顺序：先声明先构造
3.初始化中未出现的成员对象，调用默认构造构造函数（无参数）初始化
4.初始化列表完成后，再执行构造函数的函数体 

组合类必须（部件对象必须要有默认构造函数） 
 
声明形式：
类名：：类名（对象成员所需的形参，本类成员形参）：
	对象1（参数），对象2（参数），......
	{
	//函数体其它语句 
}
*/

class Point	//Point类声明
{
public:
	Point(int xx=0, int yy=0) {X=xx;Y=yy;cout<<"Point构造函数被调用"<<endl;}
	Point(Point &p);
	int GetX() {return X;}
	int GetX() const {return X;}
	int GetY() {return Y;}
	~Point()	{cout<<"Point析构函数被调用"<<endl;}
private:
	int X,Y;
};
Point::Point(Point &p)	//拷贝构造函数的实现&p表示引用 
{
	X=p.X;
	Y=p.Y;
	cout<<"Point拷贝构造函数被调用"<<endl;
}
//类的组合
class Line	//Line类的声明
{
public:	//外部接口
	Line (Point xp1, Point xp2);
	Line (Line &);
	double GetLen(){return len;}
	~Line(){cout<<"Line析构函数被调用"<<endl;}
private:	//私有数据成员
	Point p1,p2;	//Point类的对象p1,p2
	double len;	
};
//组合类的构造函数
Line:: Line (Point xp1, Point xp2)
:p1(xp1),p2(xp2)
{
	cout<<"Line构造函数被调用"<<endl;
	double x=double(p1.GetX()-p2.GetX());
	double y=double(p1.GetY()-p2.GetY());
	len=sqrt(x*x+y*y);
}

//组合类的拷贝构造函数
Line:: Line (Line &Seg): p1(Seg.p1), p2(Seg.p2)		//xp都属Piont对象; (Point xp1,Piont xp2) : p1(xp1),p2(xp2)
{
	cout<<"Line拷贝构造函数被调用"<<endl;
	len=Seg.len;
}

//主函数
int main()
{
	Point myp1(1,1),myp2(4,5);	//建立Point类的对象
	Line line(myp1,myp2);	//建立Line类的对象
	Line line2(line);	//利用拷贝构造函数建立一个新对象
	cout<<"The length of the line is:";
	cout<<line.GetLen()<<endl;
	cout<<"The length of the line2 is:";
	cout<<line2.GetLen()<<endl;
	return 0;
}

