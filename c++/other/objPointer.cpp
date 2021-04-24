/*
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
  ·当通过一个对象调用成员函数时，系统先将该对象的地址赋缘his指针，然后
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

*/
#include <iostream>
using namespace std;

class Point	//类的声明
{
public:	//外部接口
	Point(int xx = 0, int yy = 0, int tt = 0) { X = xx; Y = yy; t = tt; }	//构造函数
	int GetX() { return X; }	//内联函数，返回X
	int GetY() { return Y; }	//内联函数，返回Y
	int t;
private:	//私有数据
	int X, Y;
};

void main()	//主函数
{
	Point A(4, 5);	//声明对象A
	Point *p1 = &A;	//声明对象指针并初始化
	cout << (p1->GetX)() << endl;	//（2）使用对象指针访问成员函数
	cout << A.GetX() << endl; 	//（3）使用对象名访问成员函数
}

