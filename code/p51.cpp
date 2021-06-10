#ifndef _STACKAR_H
#define _STACKAR_H

#include "dsexceptions.h"

template <class Object>
class Stack {
public:
    explicit Stack(int capacity = 10);
    bool IsEmpty() const;
    bool IsFull() const;
    const Object & Top() const;

    void MakeEmpty() { top = -1 };
    void Pop();
    void Push(const Object & x);
    Object TopAndPop();

private:
    int   MaxSize;
    int   top;
    Object  *theArray;
};
#endif