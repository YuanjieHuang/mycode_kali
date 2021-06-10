//查找第k个元素用x返回, 查找成功返回true, 否则返回false
template<class T>
bool LinkedList<T>::Find(int k, T& x) const
{   
    if (k < 1) return false;
    ListNode<T> *current = first;
    int index = 1;  //当前索引
    while (index < k && current) {
        current = current->link;
        index++;
    }
    if (current) {
        x = current->data;
        return true;
    }
    return false; //没有第k个元素
}
