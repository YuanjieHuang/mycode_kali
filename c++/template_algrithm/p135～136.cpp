#include <stdlib.h>

template <class T>
class Array  {
private:
    //一个动态申请的包含size个元素的表
    T *alist;
    int size;
    
public:
    //构造函数和析构函数
    Array(int sz = 50);
    Array(const Array<T>& A);
    ~Array(void){delete[]alist;}
    
    //赋值、下标和指针转换操作
    Array<T>& operator=(const Array<T>& rhs);
    T& operator[](int i);
    operator T*(void) const;
    
    //有关表大小的函数
    int ListSize(void) const{return size;}	//取表的大小
    void Resize(int sz);	//修改表的大小
};

template <class T>
Array<T>::Array(int sz)
{
    if (sz <= 0)		//检查数组的大小参数是否合法
        throw "Array::Array: Invalid array size";
    size = sz;
    alist = new T[size];
}

//复制构造函数
template <class T>
Array <T>::Array(const Array<T> &A)
{
    //取得对象A的大小并将其赋值给当前对象
    int n = A.size;
    size = n;
    
    alist = new T[n];	//申请动态内存
    
    T *srcptr = A.alist;	//A.alist的首地址赋给srcptr
    T *destptr = alist;	//当前对象.alist的首地址赋给destptr
    while (n--) *destptr++ = *srcptr++;	//复制表
}

//赋值操作, 将rhs分配给当前对象
template <class T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    int n = rhs.size;	//记录rhs的大小
    
    if (size != n)  {	//如果sizes不相同, 删除内存并重新分配
        delete [] alist;	//释放原始内存
        alist = new T[n];	//分配新数组
        size = n;
    }
    
    //将数组项目从rhs复制到当前对象
    T* srcptr = rhs.alist;
    T* destptr = alist;
    while (n--) *destptr++ = *srcptr++;
    return *this;	//返回当前对象的引用
}

//重载下标运算符
template <class T>
T& Array<T>::operator[](int n)
{
    if (n < 0 || n > size - 1)	//数据越界检查
        throw "Array::operator[]: invalid index";
    return alist[n];	//从私有数组中返回元素值
}

//指针转换运算符
template <class T>
Array<T>::operator T*(void) const
{
    return alist;	//返回当前对象中私有数组的首地址
}

//调整数组大小运算符
template <class T>
void Array<T>::Resize(int sz)
{
    if (sz <= 0)	//检查新的大小参数, 若其小于等于0, 则退出算法
        throw "Array::Array: Invalid array size";
    
    if (sz == size) return;	//若大小不变, 则简单返回
    
    //需申请新的内存, 确认系统已分配所需内存
    T *newlist = new T[sz];
    
    int n = (sz < size) ? sz : size;	//n为需复制元素的个数
    
    //从旧表中复制n个数组元素的新表 
    T* srcptr = alist;	//alist的首地址赋给srcptr
    T* destptr = newlist;	//newlist的首地址赋给destptr
    while (n--) *destptr++ = *srcptr++;	//复制表
    
    delete [] alist;	//删除旧表
    
    //将alist指针指向newlist并改变大小值
    alist = newlist;
    size = sz;
}
