// ***************************************************************
// 头文件genericStack.h
// 功能：定义栈类模板Stack
// ***************************************************************
#ifndef GSTACK_H
#define GSTACK_H
#include <new>					// 使用其中的bad_alloc类
#include <stdexcept>			// 使用其中的logic_error类
// 以指针方式实现的栈类模板的定义
template <typename ElementType>
class Stack {
public:
	Stack();					// 构造函数
	~Stack();					// 析构函数
	// 栈操作
	void push(ElementType obj) throw(std::bad_alloc);
	void pop() throw(std::logic_error);
	ElementType getTop() const throw(std::logic_error);
	bool isEmpty() const;
private:
	// 栈结点类型
	struct Node {
		ElementType element;		// 结点中存放的元素
		Node* next;				// 指向下一结点的指针
	};
	Node* top;						// 栈的栈顶
};
#include "genericStack.cpp"		// 包含源文件
#endif    
