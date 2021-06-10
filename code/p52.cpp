//栈的构造
template <class Object>
Stack<Object>::Stack(int capacity) 
{ 
    MaxSize = capacity;
    top = -1;
}

//判栈空
template <class Object>
bool Stack<Object>::IsEmpty() const
{
    return top == -1;   //如果空, 返回true; 否则返回false
}

//判栈满
template <class Object>
bool Stack<Object>::IsFull() const
{
    return top == MaxSize - 1; //如果满, 返回true; 否则返回false
}

//入栈, 当栈非满时插入x到栈顶, 否则抛出异常Overflow 
template <class Object>
void Stack<Object>::Push(const Object & x)
{
    if (IsFull())  throw Overflow();
    theArray[++top] = x;
}

//出栈, 当栈非空时删除栈顶, 否则抛出异常Underflow
template <class Object>
void Stack<Object>::Pop()
{
    if (IsEmpty())  throw new Underflow();
    top--;
}

//当栈非空时返回栈顶元素并且出栈, 否则抛出异常Underflow
template <class Object>
Object Stack<Object>::TopAndPop()
{
    if (IsEmpty())  throw Underflow();
    return theArray[top--];
}

//当栈非空时返回栈顶元素, 否则抛出异常Underflow, 此操作不更新栈结构
template <class Object>
const Object & Stack<Object>::Top() const
{
    if (IsEmpty())  throw Underflow();
    return theArray[top];
}
