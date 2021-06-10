程序清单8-8
// ***************************************************************
// ambiguousDemo.cpp
// 演示因重复继承导致的二义性问题
// ***************************************************************

#include <iostream>
using namespace std;

// 祖先类
class Base {
public:
    void setData(int newData)
    {
        data = newData;
    }

protected:
    int data; 				// 受保护数据成员
};

// 基类1
class Base1:public Base {
public:
    void setData1(int newData, int newData1)
    {
        data = newData;
        data1 = newData1;
    }

protected:
    int data1;
};

// 基类2
class Base2:public Base { 
public:
    void setData2(int newData, int newData2)
    {
        data = newData;
        data2 = newData2;
    }

protected:
    int data2;
};

// 派生类，重复继承BASE类，存在二义性问题
class Derived:public Base1, public Base2 {
public:
     void setData3(int newData, int newData1, int newData2)
     {
        data = newData; // 对data的访问有二义性
        data1 = newData1;
        data2 = newData2;
     }
};

int main()
{
    Derived dObj;
    dObj.setData3(3,4,5);

    return 0;
}
