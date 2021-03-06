#ifndef MULTI_DERIVED_H
#define MULTI_DERIVED_H
// #ifdef __cplusplus
// extern c {
// #endif
#include "empty.h"

/*

当空类作为一个类的基类的时候，该空类占用的额外一个字节的内存空间在子类中将会被优化掉,
除了一种情况外：在子类的内存空间中有连续的相同类型的空类出现时,为了区分连续的空类，将不进行空基类优化。
此外，在 C++11 中，空基类优化是强制性的，不再是可选的。

*/
class Empty1 { };

class MultiDerived : public Empty, public Empty1 { };//size 1

class MultiDerived1 : public Empty { };
class MultiDerived2 : public Empty { };
class MultiDerived3 : public MultiDerived1, public MultiDerived2 { };//2


class NotEmpty
{
public:
  std::int32_t i32;
};

class MultiDerived4 : public MultiDerived1, public NotEmpty
{
public:
  Empty e;
};

class MultiDerived5 : public NotEmpty, public MultiDerived1
{
public:
  Empty e;
};

class MultiDerived6 : public NotEmpty, public MultiDerived1 { };


class Foo
{
public:
  Empty e[4];
  Derived2 d;
};

class Foo1Helper : public Empty
{
public:
  std::int8_t i8[3];
};

class Foo1 : public Empty
{
public:
  Foo1Helper d;
};

class Foo2 : public Empty
{
public:
  Foo f;
};

// #ifdef __cplusplus
// }
// #endif
#endif
