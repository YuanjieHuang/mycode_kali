//析构函数
template<class T>
LinkedStack<T> :: ~ LinkedStack()
{   
    Node<T> *next;
    while (top) {
        next = top->link;
        delete top;
        top = next;
    }
}

//栈是否满
template<class T>
bool LinkedStack<T>::IsFu11() const
{   
    try { 
        Node<T> *p = new Node<T>;
        delete p;
        return false; 
    }  catch (NoMem) { return true; }
}

//返回栈顶元素
template<class T>
T LinkedStack<T>::Top() const
{   
    if (IsEmpty()) throw OutOfBounds();
    return top->data;
}

//添加元素x
template<class T>
LinkedStack<T>& LinkedStack<T>::Push(const T& x)
{   
    Node<T> *p = new Node<T>;
    p->data = x;
    p->link = top;
    top = p;
    return *this;
}

//删除栈顶元素, 并将其送入x
template<class T>
LinkedStack<T>& LinkedStack<T>::Pop(T& x)
{   
    if (IsEmpty()) throw OutOfBounds();
    x = top->data;
    Node<T> *p = top;
    top = top->link;
    delete p;
    return *this;
}
