程序清单8-9
// ***************************************************************
// virtualBaseDemo.cpp
// 演示多重继承中虚基类的使用
// ***************************************************************

// 祖先类
class Base {
public:
    void setData(int newData)
	{
        data = newData;
     }
protected:
    int data;
};

// 基类1，Base是其虚基类
class Base1:virtual public Base {
public:
    void setData1(int newData, int newData1)
	{
        data = newData;
        data1 = newData1;
     }

protected:
    int data1;
};

// 基类2，Base是其虚基类
class Base2:virtual public Base {
public:
    void setData2(int newData, int newData2)
	{
        data = newData;
        data2 = newData2;
	}

protected:
    int data2;
};

// 派生类，只有Base类中数据的一个副本
class Derived:public Base1, public Base2 {
public:
    void setData3(int newData, int newData1, int newData2)
	{
        data = newData;  // 不会出现二义性
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
