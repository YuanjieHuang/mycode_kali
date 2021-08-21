//在以root为头结点的中序线索二叉树中查找值为x的结点
template <class T>
ThreadBinaryTreeNode<T>*  Find(ThreadBinaryTreeNode<T> *root, T x)
{
    ThreadBinaryTreeNode<T> *p;
    p = root->leftchild();
    while (p->ltag == Link&&p != root) p = p->leftchild();
    while(p != root && p->value() != x) p = FindNextinInorderTree(p);
    if (p == root) {
        cerr << "Not Found the data!" << endl;
        return(0);
    }
    else  return(p);
}
