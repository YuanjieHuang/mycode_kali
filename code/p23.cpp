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
