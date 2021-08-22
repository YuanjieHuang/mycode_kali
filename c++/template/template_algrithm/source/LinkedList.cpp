#include "LinkedList.h"
#include <iostream>
using namespace std;
//创建一个单向链表, finished是停止建表输入标志, 是所有输入值中不可能出现的数值
template <class Type>
LinkedList <Type> :: LinkedList()
{  
    ListNode<Type> *p;
    first =  NULL;	//创建空表
    Type value;	
    cin >> value;   
    while (value != finished)  {  
        p= new ListNode<Type>(value, first);
        first = p;
        cin >> value;  
    }
}
//创建一个单向链表, finished是停止建表输入标志, 是所有输入值中不可能出现的数值
template <class Type>
LinkedList <Type>::LinkedList() 
{ 
    ListNode<Type> *p, *rear;
    Type value;	
    first = NULL;
    rear = NULL;
    cin >> value;   
    while (value != finished) {
        p= new ListNode<Type>(value, NULL);
        if (first == NULL)  first = p;  	//第一个结点的处理 
        else  rear->link = p;       		//其他结点的处理 
        rear = p;        					//r指向新的尾结点
        cin >> value;   
    }
    if (rear !＝ NULL)  rear->link = NULL; //对非空表, 最后结点的指针域放空指针 
}
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
//如果找到 x, 返回其位序, 否则返回0
template<class T>
int LinkedList<T>::Search(const T& x) const
{   
    ListNode<T> *current = first;
    int index = 1;  //当前索引
    while (current && current->data != x) {
        current = current->link;
        index++;
    }
    if (current) return index;
    return 0;
}
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

template<class Type> 
void LinkedList<Type>::Inverse () 
{
	ListNode<Type> *p, *head = new ListNode<Type> ();
	while (first != NULL) {
		p = first;  first = first->link;		//摘下first链头结点
		p->link = head->link;  head->link = p;	//插入head链前端
	}
	first = head->link; delete head;			//重置first
}

