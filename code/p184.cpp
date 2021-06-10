//在中序穿线树中找指定结点在中序下的后继
template <class T>
ThreadBinaryTreeNode<T>* ThreadBinaryTree<T>::FindPriorinInorderTree(ThreadBinary
                                                 	TreeNode<T>* pointer)

{
    ThreadBinaryTreeNode<T>* temppointer = NULL;
    if (pointer->lTag == Thread)
        return pointer->leftchild();
    else {
        temppointer = pointer->leftchid();
        while (temppointer->rTag == Link)
            temppointer = temppointer->rightchild();
        return temppointer;
    }
}
