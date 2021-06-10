//删除第k个元素, 值用x返回
template<class T>
LinkedList<T>& LinkedList<T>::Delete(int k, T& x)
{
    if (k < 1 || !first) throw OutOfBounds(); //没有第k个元素
   
    //查找第k个结点, 用p指向它
    ListNode<T> *p = first;

    if (k == 1) 	//p已经是第k个元素
        first = first->link; //从链中删除
    else { 	//用q记录第k-1元素
        ListNode<T> *q = first;
        for (int index = 1; index < k - 1 && q; index++)
            q = q->link;
        if (!q || !q->link) throw OutOfBounds();	//没有第k个元素
        p = q->link; 	//记录被删结点
        q->link = p->link;
    } 		//从链中删除
    //保存第k个元素并且回收结点
    x = p->data;
    delete p;
    return *this;
}
