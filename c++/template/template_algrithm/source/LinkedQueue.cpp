//析构函数
template<class T>
LinkedQueue<T>::~LinkedQueue()
{ 
    Node<T> *next;
    while (front) {
        next = front->link; 
        delete front; 
        front = next;
    }
}

//队列非空时, 返回队首元素
template<class T>
T LinkedQueue<T>::GetFront() const
{ 
    if (IsEmpty()) throw OutOfBounds();
    return front->data;
}

//队列非空时, 返回队尾元素
template<class T>
T LinkedQueue<T>::GetRear() const
{ 
    if (IsEmpty()) throw OutOfBounds();
    return rear->data;
}

//入队
template<class T>
LinkedQueue<T>& LinkedQueue<T>::EnQueue(const T& x)
{ 
    //创建新结点
    Node<T> *p = new Node<T>;
    p->data = x;
    p->link = 0;

    //新结点入队
    if (front) rear->link = p;  //队列非空
    else front = p;             //队列空
    rear = p;

    return *this;
}

//队列非空时, 出队并且返回队首元素
template<class T>
LinkedQueue<T>& LinkedQueue<T>::DeQueue(T& x)
{ 
    if (IsEmpty()) throw OutOfBounds();

    //保存队首元素
    x = front->data;

    //删除队首结点
    Node<T> *p = front;
    front = front->link;
    delete p;

    return *this;
}
