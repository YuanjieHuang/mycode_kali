//文件abslist.h：类AbstractList
#ifndef AbstractList_
#define AbstractList_

template<class T>
class AbstractList {
public:
    virtual bool IsEmpty() const = 0;
    virtual int Length() const = 0;
    virtual bool Find(int k, T& x) const = 0;	//用x返回第k个元素
    virtual int Search(const T& x) const = 0;	//返回x的位置
    //删除第k个元素并且用x返回
    virtual AbstractList<T>& Delete(int k, T& x) = 0;
    //在第k个元素后面插入x
    virtual AbstractList<T>& Insert(int k, const T& x) = 0;
    virtual void Output(ostream& out) const = 0;
};

#endif