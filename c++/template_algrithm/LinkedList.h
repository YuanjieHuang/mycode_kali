//文件LinkedList.h，链表的类定义
#ifndef LinkedList_
#define LinkedList_

#include <iostream.h>
#include "node.h"

template<class T>
class LinkedList {
public:
    LinkedList() { first = 0; }
    ~LinkedList();
    bool IsEmpty() const { return first = = 0; }
    int Length() const; 
    bool Find(int k, T& x) const; 
    int Search(const T& x) const; 
    ListNode<T> *First() { return first; }
    LinkedList<T>& Delete(int k, T& x); 
    LinkedList<T>& Insert(int k, const T& x);
    void Output(ostream& out) const;
private:
    ListNode<T> *first;  //头指针
};
#endif
