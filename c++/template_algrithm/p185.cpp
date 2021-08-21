//在中序线索树中找指定结点在后序下的前驱结点
template <class T>
ThreadBinaryTreeNode<T>*ThreadBinaryTree<T>::FindPostPriorinInorderTree
                                               (ThreadBinaryTreeNode<T>* pointer)

{
    ThreadBinaryTreeNode<T>* temppointer = NULL;
    if (pointer->rTag == Link)
        return pointer->rightchild();
    else {
        temppointer = pointer;
        while(temppointer->lTag == Thread)
            temppointer = temppointer->leftchild();
        temppointer = temppointer->leftchild();
        return temppointer;
    }
}
