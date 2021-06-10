//在第k个元素后插入一个元素值为x的结点
template<class T>
LinkedList<T>& LinkedList<T>::Insert(int k, const T& x)
{
    if (k < 0) throw OutOfBounds();

    //查找第k个结点, 用p指向它
    ListNode<T> *p = first;
    for (int index = 1; index < k && p; index++) 
        p = p->link;
    if (k > 0 && !p) throw OutOfBounds(); //没有第k个结点

    //插入
    ListNode<T> *s = new ListNode<T>;
    s->data = x;
    if (k) {	//插在*p后面
        s->link = p->link;
        p->link = s;
    }
    else {		//如果k==0, 插入作为第一个元素
        s->link = first;
        first = s;
    }
    return *this;
}
