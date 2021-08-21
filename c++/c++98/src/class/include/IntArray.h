#ifndef _array_h
#define _array_h

#include <iostream>
using namespace std;

class IntArray
{ 
    friend ostream &operator<<(ostream &os, const IntArray &obj);
    friend istream &operator>>(istream &is, IntArray &obj);
    friend bool operator==(const IntArray &obj1, const IntArray &obj2);

private:
    int low;  
    int high;
    int *storage;

public:
    //根据low和high为数组分配空间。分配成功，返回值为true,否则为false
    IntArray(int lh = 0, int rh = 0):low(lh),high(rh)
    {storage = new int [high - low + 1]; }

    //复制构造函数
    IntArray(const IntArray &arr);
	
    //赋值运算符重载函数
    IntArray & operator=(const IntArray & a);

    //下标运算符重载函数
    int & operator[](int index);
    const int &operator[](int index) const;

    //获取数组规模
    void getSize() {cout << "下标范围为：[" << low << ", " << high << "]\n";}

    //回收数组空间
    ~IntArray() {delete [] storage; }
};

#endif