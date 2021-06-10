#ifndef _QUEUEAR_H
#define _QUEUEAR_H
#include "dsexceptions.h"

template <class Object>
class Queue {
public:
	Queue(int capacity = 10);
	bool IsEmpty() const;
	bool IsFull() const;
	const Object & GetFront() const;
	void MakeEmpty();
	Object DeQueue();
	void EnQueue(const Object & x);
private:
	Object * theArray ;
	int MaxSize , currentSize;
	int front;
	int rear;
	void increment(int & x);//给x增1
};
#endif
