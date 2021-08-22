//文件node.h，结点类ListNode
#ifndef ListNode_
#define ListNode_

template <class T> class LinkedList;       	//前视定义,否则友元无法定义
template <class T>                        	//模板类型为T
class ListNode{
    friend class LinkedList<T>;           	//定义类LinkedList<T>为友元
private:
    ListNode<T> *link;                    	//指向下一结点的指针
    T data;                               	//定义为私有成员
public:
    //构造函数1,用于构造头结点
    ListNode(ListNode<T> *ptrlink = NULL)
    { link = ptrlink; }

    //构造函数2,用于构造其他结点
    ListNode(const T& item, ListNode<T> *ptrlink = NULL)
    { data = item; link = ptrlink; }

    ~ListNode(void){}                		//析构函数
                                          	//以item和next建立一个新结点
    ListNode<T> * getNode(const T& item, ListNode<T> *next = NULL)
    ListNode<T> * getLink() { return link; }  	//取得结点的下一结点地址
    T getData() { return data; }             	//取得结点中的数据
    void setLink(ListNode<T> * next) { link = next; }	//修改结点的link域
    void setData(T value) { data = value; }        	//修改结点的data值    

};
#endif