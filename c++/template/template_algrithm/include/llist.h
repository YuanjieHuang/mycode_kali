//文件llist.h：类LinearList
#ifndef LinearList_
#define LinearList_
#include<stdlib.h>
#include<iostream.h>
#include "abslist.h"

template<class T>
class LinearList : AbstractList<T> {
public:
    LinearList(int MaxListSize = 10); 	//构造函数
    ~LinearList() { delete [] element; }	//析构函数
    bool IsEmpty() const { return length == 0; }
    int Length() const { return length; }
    bool Find(int k, T& x) const; 	//用x返回第k个元素
    int Search(const T& x) const; 	//返回x的位置
    //删除第k个元素并且用x返回
    AbstractList<T>& Delete(int k, T& x);
    //在第k个元素后面插入x
    AbstractList<T>& Insert(int k, const T& x);
    void Output(ostream& out) const;
private:
    int length;
    int MaxSize;
    T *element; //动态数组
};
#endif
