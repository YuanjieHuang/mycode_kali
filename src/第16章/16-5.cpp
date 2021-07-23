　　template <class elemType>
　　void linkList<elemType>::makeEmpty()
　　{   Node  *p, *q;
　　
　　    p = head->next;
　　    head->next = NULL; //将链表设为空链表
　　
　　    while ( p != NULL) { q=p->next; delete p; p = q;} //回收链表中的所有结点
　　}
　　
