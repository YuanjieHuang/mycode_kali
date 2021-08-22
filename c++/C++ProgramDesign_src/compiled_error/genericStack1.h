// ***************************************************************
// genericStack.h
// 功能：定义并实现栈类模板Stack
// ***************************************************************
#ifndef GSTACK_H
#define GSTACK_H
#include <new>					// 使用其中的bad_alloc类
#include <stdexcept>			// 使用其中的logic_error类
// 以指针方式实现的栈类模板的定义
template <typename ElementType>
class Stack {
public:
	// 构造函数
	Stack();
	// 将栈顶置为空指针
	// 后置条件：对象的数据成员top置为NULL（空指针） 
	// 析构函数
	~Stack();
	// 释放栈元素所占用的内存
	// 栈操作
	void push(ElementType obj) throw(std::bad_alloc);
	// 将元素obj压入栈
	// 前置条件：obj已赋值
	// 后置条件：以obj为元素创建的新结点成为新的栈顶
	void pop() throw(std::logic_error);
	// 将当前栈顶的元素弹出栈
	// 前置条件：栈不为空
	// 后置条件：当前栈顶元素的下一结点成为新的栈顶
	ElementType getTop() const throw(std::logic_error);
	// 返回当前栈顶的元素值
	// 前置条件：栈不为空
	bool isEmpty() const;
	// 判断栈是否为空
	// 后置条件：如果栈为空，则函数返回值为true否则函数返回值为false
private:
	// 栈结点类型
	struct Node {
		ElementType element;	// 结点中存放的元素
		Node* next;			// 指向下一结点的指针
	};
	Node* top;					// 栈的栈顶
};
// 栈类模板的实现
// 构造函数
template <typename ElementType>
Stack<ElementType>::Stack()
// 将栈顶置为空指针
{	
	top = NULL;					// 将栈顶置为空
}
// 析构函数
template <typename ElementType>
Stack<ElementType>::~Stack()
// 释放栈元素所占用的内存
{
	while (top != NULL) {
		pop();
	}
}
// 栈操作
template <typename ElementType>
void Stack<ElementType>::push(ElementType obj) throw(std::bad_alloc)
// 将元素obj压入栈
{
	Node* temp;
	try {
		temp = new Node;			// 创建一个新结点
		temp -> element = obj;		// 新结点的元素赋值
		temp -> next = top;		// 原来的栈顶结点作为新结点的下一结点
		top = temp;				// 修改栈顶指针：将新结点置为栈顶结点
	} 
	catch (std::bad_alloc e) {		// 内存分配失败时进行异常处理
		throw;						// 重新抛出异常
	}
}
template <typename ElementType>
void Stack<ElementType>::pop() throw(std::logic_error)
// 将当前栈顶的元素弹出栈
{
	Node* temp;
	if (top != NULL) {			// 栈不为空时才进行弹出处理
		temp = top;			
		top = top -> next;			// 将原栈顶的下一结点设为栈顶
		delete temp;				// 释放被弹出结点占用的存储空间
	} 
	else {							// 栈为空时抛出异常
		throw std::logic_error("pop from empty Stack");
	}
}
template <typename ElementType>
ElementType Stack<ElementType>::getTop() const throw(std::logic_error)
// 返回当前栈顶的元素值
{
	if (top == NULL) {			// 如果栈为空则抛出异常
		throw std::logic_error("get top from empty Stack");
	}
	return top->element;			// 返回栈顶的当前值
}
template <typename ElementType>
bool Stack<ElementType>::isEmpty() const
// 判断当前栈是否为空，空则返回true，否则返回false
{
	return (top == NULL);
}
#endif    
