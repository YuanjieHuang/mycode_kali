#ifndef EMPTY_H
#define EMPTY_H
#include <iostream>
#include <cstdio>
class Empty { };

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