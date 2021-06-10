//返回链表中元素的个数
template<class T>
int LinkedList<T>::Length() const
{   
    ListNode<T> *current = first;
    int len = 0;
    while (current) {
        len++;
        current = current->link;
    }
    return len;
}
