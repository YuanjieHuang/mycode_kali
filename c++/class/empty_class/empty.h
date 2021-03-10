#ifndef EMPTY_H
#define EMPTY_H
#include <iostream>
#include <cstdio>
/*
  我们利用类型（通常是空类）来区别对待不同类对象的属性。（其实我们是可以通过使用常数来区分的，但是区别我们很容易就能知道）。
  使用常数来区分需要使用if else的这种运行时来确定执行的线路的方法，而使用函数重载的方法，在参数中加入一个空类域作为区分不同的函数的方法，
  编译的时候直接选择，而不是在运行的时候选择，这是非常提高效率的。
  要知道，不同的空类，是不同的。他们代表着不同的类型(虽然他们结构一样）。
  在STL中，使用空类区分不同类型的标志，从而在编译的时候来对不同的类进行有针对性的优化是非常常见的。
*/


// class Empty { };
//  一个空的class在C++编译器处理过后就不再为空，编译器会自动地为我们声明一些member function，一般编译过去就相当于
class Empty
{
public:
Empty(); // 缺省构造函数
Empty( const Empty& ); // 拷贝构造函数
~Empty(); // 析构函数
Empty& operator=( const Empty& ); // 赋值运算符
Empty* operator&(); // 取址运算符
const Empty* operator&() const; // 取址运算符 const
};

// 如果你只是声明一个空类，不做任何事情的话，编译器会自动为你生成一个默认构造函数、一个拷贝默认构造函数、一个默认拷贝赋值操作符和一个默认析构函数。
// 这些函数只有在第一次被调用时，才会别编译器创建。所有这些函数都是inline和public的。

class Derived1 : public Empty { };//1

class Derived2 : public Empty//4
{
public:
  std::int32_t i32;
};

class Derived3 : public Derived1 { };//1

class Derived4 : public Derived1//4
{
public:
  std::int32_t i32;
};

/*
Derived5,此时空基类优化失去了效果。如果依然进行优化，则无法区分基类 Empty 和子类中的成员Empty
（注意子类 Derived5 中的 Empty 不是基类，所以不参与优化，一定会占用一个字节）。
*/
class Derived5 : public Empty//size 2  
{
public:
  Empty e;
};

class Derived6 : public Empty// size 1
{
public:
  static Empty se;
};
Empty Derived6::se { };

#pragma pack(1)
class Derived7 : public Empty
{
public:
  std::int32_t i32;
  Empty e;
};
#pragma pack()


class EmptyWithVirtualFunc//8
{
public:
  virtual void VirtualFunc() { }
};

class EmptyWithMenFunc//1
{
  void getmember();
};
class EmptyWithStaticMem//1
{
  static int64_t int_64;
};
#endif