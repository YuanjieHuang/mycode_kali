#ifndef _STACKLI_H
#define _STACKLI_H

#include "dsexceptions.h"
#include <iostream.h>

template <class Object>
class Stack { 
public:
    Stack();
    Stack(const Stack & rhs);
    ~Stack();

    bool IsEmpty() const;
    bool IsFull() const;
    const Object & Top() const;

    void MakeEmpty();
    void Pop();
    void Push(const Object & x);
    Object TopAndPop();
private:
    struct ListNode {
        Object   element;
        ListNode *next;

        ListNode(const Object & theElement, ListNode * n = NULL)
                 : element(theElement), next(n) {}
    };

    ListNode *topOfStack;
};
#endif

