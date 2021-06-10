//查找x, 如果找到, 则返回x所在的位置; 如果x不在表中, 则返回0
template<class T>
int LinearList<T>::Search(const T& x) const
{ 
    for (int i = 0; i < length; i++) 
        if (element[i] == x)  return ++i;
    return 0;
}
