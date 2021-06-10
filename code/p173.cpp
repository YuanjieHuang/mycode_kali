//层次遍历
template<class T>
void BinaryTree<T>::LevelOrder(void(*Visit) (BinaryTreeNode<T> *u))
{  
    LinkedQueue < BinaryTreeNode<T>*> Q;
    BinaryTreeNode<T> *t;
    t = root;
    while (t) { //树非空时
        Visit(t);
        if (t->GetLeft()) Q.EnQueue(t->GetLeft());   //左孩子入队
        if (t->GetRight()) Q.EnQueue(t->GetRight()); //右孩子入队
        try
        { Q.DeQueue(t); }
        catch (OutOfBounds) 
        { return; }
    }
}
