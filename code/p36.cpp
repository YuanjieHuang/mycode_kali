//此算法将两个采用尾指针的循环链表首尾连接起来
template <class T>
CNode<T> *   merge_1( CNode<T> *  RA, CNode<T>*RB)
{   
    CNode<T> *p;
    p = RA->NextNode(); 	//保存链表RA的头结点地址
    RA->InsertAfter(RB->next->next);	//RB的开始结点链到RA的终端结点后
    delete RB->NextNode();	//释放链表RB的头结点
    RB->InsertAfter(p);	//链表RA的头结点链到链表RB的终端结点之后
    return  RB;		//返回新循环链表的尾指针
}
