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

#endif
