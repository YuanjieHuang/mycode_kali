#include "QueueAr.h"

//判队空, 返回true或false
template <class Object>
bool Queue<Object>::IsEmpty() const
{
	return currentSize == 0;
}

//判队满, 返回true或false
template <class Object>
bool Queue<Object>::IsFull() const
{
	return currentSize == MaxSize;
}

//置队空
template <class Object>
void Queue<Object>::MakeEmpty()
{
	currentSize = 0;
	front = 0;
	rear = -1;
}

//队非空时返回队首元素, 否则报错
template <class Object>
const Object & Queue<Object>::GetFront() const
{
	if (IsEmpty())  throw Underflow();
	return theArray[front];
}

//队非空时返回并且出队队首元素, 否则报错 
template <class Object>
Object Queue<Object>::DeQueue()
{
	if (IsEmpty())  throw Underflow();

	currentSize--;
	Object frontItem = theArray[front];
	Increment(front);
	return frontItem;
}

//队非满时插入元素到队尾, 否则报错 
template <class Object>
void Queue<Object>::EnQueue(const Object & x)
{
	if (IsFull())  throw Overflow();
	Increment(rear);
	theArray[rear] = x;
	currentSize++;
}

//内部的增1方法
template <class Object>
void Queue<Object>::Increment(int & x)
{
	++x;
}
