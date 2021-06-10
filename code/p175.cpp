//非递归中序遍历二叉树
template<class T>
void BinaryTree<T>::InOrderWithoutRecusion(BinaryTreeNode<T>* root)	
{
    using std::stack;
    stack<BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T>* pointer = root;		//保存输入参数	

    While (!aStack.empty() || pointer) {

        while (pointer) {
            aStack.push(pointer);			//当前结点地址入栈
            pointer = pointer->GetLeft();	//当前链接结构指向左孩子
        }
        if (!aStack.empty()) {       		//左子树访问完毕, 转向访问右子树
            pointer = aStack.top();				
            Visit(pointer->data);	     	//访问当前结点
            Pointer = pointer->GetRight(); 	//当前链接结构指向右孩子
            aStack.pop();					//栈顶元素退栈                 
        } 
    } 
}
