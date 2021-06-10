//此算法将两个采用头指针的循环单向链表的首尾连接起来
template <class T>
CNode<T> *   merge_1( CNode<T> *  LA, CNode<T>* LB)
{   
    CNode<T> *p, *q;
    p = LA;
    q = LB;
    while (p->NextNode() != LA)
        p = p->NextNode();    	//找到表LA的表尾, 用p指向它
    while (q->NextNode() != LB) 
        q = q->NextNode();    	//找到表LB的表尾, 用q指向它
    q->InsertAfter(LA);   	//修改表LB 的尾指针, 使之指向表LA 的头结点
    p->InsertAfter(LB->next);	//修改LA的尾指针, 使之指向LB的第一个结点
    delete LB;
    return (LA);
}
