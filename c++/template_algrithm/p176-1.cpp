//非递归后序遍历二叉树
template<class T>
void BinaryTree<T>::PostOrderWithoutRecusion(BinaryTreeNode<T>* root)
{ 
    using std::stack;
    StackElement<T> element;
    stack<StackElement<T>> aStack;
    BinaryTreeNode<T>* pointer;
    if (NULL == root)
        return;		//空树即返回
    else pointer = root;
    while (true) {
        //进入左子树
        while (pointer! = NULL) {
            element.pointer = pointer;
            element.tag = LEFT;
            aStack.push(element);
            pointer = pointer->GetLeft();
        }

        if (!aStack.empty()){
            element = aStack.top();   	//弹出栈顶元素
            aStack.pop();
            pointer = element.pointer;
            if (element.tag == RIGHT) {	//从右子树回来
                Visit(pointer->data);	//访问当前结点
                if (aStack.empty())
                    return;
                else {
                    element = aStack.top();
                    aStack.pop();
                    pointer = element.pointer;
                }
            }
            else {	//从左子树回来 
                element.tag = RIGHT;
                aStack.push(element);
                pointer = pointer->GetRight();
            }
        }
    }
}
