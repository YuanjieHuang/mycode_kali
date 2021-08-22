//链队列类型定义：lqueue.h头文件
#ifndef LinkedQueue_
#define LinkedQueue_
#include "node.h"
#include "xcept.h"

template<class T>
class LinkedQueue {  //先进先出对象
public:
    LinkedQueue() {front = rear = 0;}	//构造函数
    ~LinkedQueue(); 					//析构函数
    bool IsEmpty() const
    { return ((front) ? false : true); }
    T GetFront() const; 				//返回队首元素
    T GetRear() const; 				//返回队尾元素

    LinkedQueue<T>& EnQueue(const T& x);
    LinkedQueue<T>& DeQueue(T& x);
private:
    Node<T> *front;  //指向队首结点
    Node<T> *rear;   //指向队尾结点
};
#endif
