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
