程序清单13-6
// ***************************************************************
// 实现文件genericStack.cpp
// 功能：实现栈类模板Stack
// ***************************************************************

// 构造函数
template <typename ElementType>
Stack<ElementType>::Stack()
// 将栈顶置为空指针
{
	top = NULL;				// 将栈顶置为空
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
// ...其他操作的定义略
