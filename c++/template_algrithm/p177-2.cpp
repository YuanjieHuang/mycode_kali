template <class T>
TreeNode<T> *GetTreeNode(T item, BinaryTreeNode<T> *lptr = NULL, 
                             BinaryTreeNode<T> *rptr = NULL)
{
    TreeNode<T> *p;
    p = new TreeNode<T> (item, lptr, rptr);
    if (p == NULL)  
        exit(1);
    return p;
}

template <class T>
BinaryTreeNode<T> *CopyTree(BinaryTreeNode<T> *t)
{  
    BinaryTreeNode<T> *newlptr, *newrptr, *newnode;

    if (t == NULL)    return NULL;
    if (t->GetLeft() != NULL) 
        newlptr = CopyTree(t->GetLeft());
    else  newlptr = NULL;
    if (t->GetRight() != NULL) 
        newrptr = CopyTree(t->GetRight());
    else  newrptr = NULL;
    newnode = GetTreeNode(t->data, newlptr, newrptr);
    return newnode;
}
