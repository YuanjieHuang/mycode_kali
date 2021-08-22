#ifndef CIRCULAR_NODE_CLASS
#define CIRCULAR_NODE_CLASS

template <class T>
class CNode {
private:
    CNode<T> *link;
public:
    T data;
        
    //构造函数
    CNode(void);
    CNode (const T& item);
        
    //链表更新方法
    void InsertAfter(CNode<T> *p);
    CNode<T> *DeleteAfter(void);
        
    //获取下一结点地址
    CNode<T> *NextNode(void) const;
};
    //初始化结点使其指向自身
template <class T>
CNode<T>::CNode(void)
{
    link = this;
}
//初始化结点使其指向自身, 并且初始化数据域
template <class T>
CNode<T>::CNode(const T& item)
{
    link = this;
    data = item;
}
  
//返回下一结点地址
template <class T>
CNode<T> *CNode<T>::NextNode(void) const
{
    return link;
}

//在当前结点后插入*p
template<class T>
void CNode<T>::InsertAfter(CNode<T> *p)
{
    p->link = link;    //将当前结点的后继作为p的后继, 然后将当前结点指向p
    link = p;
}

//删除当前结点的后继, 并且返回其地址
template <class T>
CNode<T> *CNode<T>::DeleteAfter(void)
{
    CNode<T> *tempPtr = link;  	//暂存被删结点
    
    if (link == this)    	//如果被删结点是自身, 返回 NULL
        return NULL;
        
    link = tempPtr->link; 	//使当前结点指向被删结点的后继
    
    return tempPtr;   	//返回被删结点地址
}

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


#endif
