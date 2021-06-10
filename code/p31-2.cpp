//如果找到 x, 返回其位序, 否则返回0
template<class T>
int LinkedList<T>::Search(const T& x) const
{   
    ListNode<T> *current = first;
    int index = 1;  //当前索引
    while (current && current->data != x) {
        current = current->link;
        index++;
    }
    if (current) return index;
    return 0;
}
