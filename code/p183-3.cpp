//T指向头结点, 头结点的左链指向根结点, 头结点的右链指向中序遍历的最后一个结点
//中序遍历二叉线索链表表示的二叉树T
template <class T>
void ThreadBinaryTree<T>::InOrder(ThreadBinaryTreeNode <T> *T, void Visit(T& item)) 
{

    p = T->leftchild(); 	//p指向根结点
    while (p != T) {     	//空树或遍历结束时p==T
        while (p->LTG() == Link)  p = p->leftchild();
        Visit(p->data);	//访问其左子树为空的结点
        while(p->RTG() == Thread&&p->rightchild() != T) {
            p = p->rightchild();  Visit(p->data); //访问后继结点
        }
        p = p-> rightchild();      //p进至其右子树根
    }
}
