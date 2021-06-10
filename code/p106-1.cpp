//若广义表非空, 则返回其第一个元素的值, 否则函数没有定义
template <class T>
GLNode<T> GenList::Head() {
    if (first == NULL) return NULL;
    else                  //非空表
        if first ->tag == 1 return first ->hp;
        else  return  first ->data;
}

template <class T>
GLNode<T> GenList::Tail()
{
    if (first == NULL) return NULL;
    else               //非空表      
        return  first ->tp;
}
