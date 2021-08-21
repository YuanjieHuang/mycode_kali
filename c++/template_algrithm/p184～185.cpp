//在中序线索树中找指定结点在先序下的后继结点
template <class T>
ThreadBinaryTreeNode<T>* ThreadBinaryTree<T>::FindPreNextinInorderTree
                             (ThreadBinaryTreeNode<T>* pointer)		

{
    ThreadBinaryTreeNode<T>* temppointer=NULL;
    if (pointer->lTag == Link)
        return pointer->leftchild();
    else {
        temppointer = pointer;
        while(temppointer->rTag == Thread)
            temppointer = temppointer->rightchild();
        temppointer = temppointer->rightchild();
        return temppointer;
    }
}
