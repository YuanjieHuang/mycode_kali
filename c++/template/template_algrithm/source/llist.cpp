#include "llist.h"
 //将所有在Lb中但不在La中的元素插入到La中
void union(LinearList &La, LinearList Lb) 
{
    La_len = La.Length();
    Lb_len = Lb.Length();	//求线性表的长度
    for (i = 1;　i <= Lb_len;　i++) {
        Lb.Find(i, e); 	//取Lb中第i个数据元素赋给e
        if(!La.Search(e)) 	//La中不存在和e相同的元素, 则将e插入到La中
        La.Insert(++La_len, e);  
    }
}

 //已知线性表Lb中的元素依值非递减有序排列, 构造线性表La, 使La中只包含Lb中所有值不相同的元素
void purge(LinearList &La, LinearList Lb) {
    La.Create();  //初始化La为空表
    La_len = La.Length();
    Lb_len = Lb.Length(); 	//求线性表的长度
    for (i = 1;  i <= Lb_len;  i++) {
        Lb.Find(i, e);  	//取Lb中第i个元素赋给e
        if (La.IstEmpty() || !equal(en, e))  
           La.Insert(++La_len, e);    //La中不存在和e相同的元素, 则将e插入之
        en = e;
    } 
}

//已知线性表La和Lb中的元素按值非递减排列, 归并La和Lb得到新的线性表Lc, Lc的元素也按值非递减排列
void MergeList(LinearList La, LinearList Lb, LinearList &Lc) {
    Lc.Create(); 
    i = j = 1;　k = 0;
    La_len = La.Length();
    Lb_len = Lb.Length();
    while ((i <= La_len) && (j <= Lb_len)) {  //La和Lb均非空
        La.Find(i, ai);  Lb.Find(j, bj);
        if (ai <= bj) { Lc.Insert(++k, ai);  ++i; }
        else { Lc.Insert(++k, bj);  ++j; }
    }
    while (i <= La_len) {
        La.Find(i, ai);
        Lc.Insert(++k, ai);
    }
    while (j <= Lb_len) {
        Lb.Find(j, bj);
        Lc.Insert(++k, bj);
    }
}

template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
    MaxSize = MaxListSize;
    element = new T[MaxSize];
    length = 0;
} 

//把第k个元素取至x中
template<class T> 
bool LinearList<T>::Find(int k, T& x) const  
{ 
    //如果不存在第k个元素, 则返回false, 否则返回true
    if (k < 1 || k > length) return false; 	//不存在第k个元素
    x = element[k - 1];
    return true;
}

//查找x, 如果找到, 则返回x所在的位置; 如果x不在表中, 则返回0
template<class T>
int LinearList<T>::Search(const T& x) const
{ 
    for (int i = 0; i < length; i++) 
        if (element[i] == x)  return ++i;
    return 0;
}

template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x)
{   //在第k个位置插入x, 如果不存在第k个位置, 则引发异常OutOfBounds
    if (k < 0 || k > length + 1) throw OutOfBounds();
    //如果表已经满, 则引发异常NoMem
    if (length == MaxSize) throw NoMem();
    //向后移动一个位置
    for (int i = length - 1; i >= k; i--)
        element[i+l] = element[i];
    element[k] = x;
    length++;
    return *this;
}


//把第k个元素放入x中, 然后删除第k个元素
template<class T>
LinearList<T>& LinearList<T>::Delete(int k, T& x)
{   
    //如果不存在第k个元素, 则引发异常OutOfBounds
    if (k < 1 || k > length) throw OutOfBounds(); //length等于表长n
    //把元素k+l, ...向前移动一个位置
    for (int i = k; i < length; i++)
        element[i-l] = element[i];
    length--;
    return *this;
}

template<class T>
int compare(LinearList<T> A, LinearList<T> B, int m, int n)
{  
    LinearList<T> AS, BS;
    int i=0,j, ms=0,ns=0;  //AS,BS作为A′,B′
    while (A.element[i] == B.element[i]) i++;  	//找最大共同前缀
    for (j=i; j<m; j++){
        AS.element[j-i] = A.element[j]; ms++; 	//求A′,ms为A′的长度
    } 
    for (j=i; j<n; j++){
        BS.element [j-i] = B.element[j]; ns++; 	//求B′,ms为B′的长度
    } 
    if (ms == ns && ms == 0) return 0;
    else if (ms == 0&&ns>0 || ms>0 && ns>0 && AS.element[0]<BS.element[0])
        return –1;
    else return 1;
}

