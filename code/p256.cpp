//顺序搜索的迭代算法, 0号元素为监视哨
template <class Type>
int SqSTable <Type>::Search(const Type & x) const
{
    Element[0].setKey (x);
    int i = CurrentSize;
    while (Element[i].getKey () != x) i--;
    return i;
}
