//递归主序线索化二叉树
template <class T>
void ThreadBinaryTree<T>::InThread(ThreadBinaryTreeNode<T>* root,
                                   ThreadBinaryTreeNode<T>* &pre)
{   
    if (root != NULL) {
        InThread(root->leftchild(), pre); 		//中序线索化左子树
        if (root->leftchild() == NULL) {		//建立前驱线索
            root->left = pre;			
            root->lTag = Thread;
        }
        if ((pre)&&(pre->rightchild() == NULL)) {	//建立后继线索
            pre->right = root;
            pre->rTag = Thread;
        }
        pre = root;
        InThread(root->rightchild(), pre); 		//中序线索化右子树
    }
}
//中序遍历二叉树T, 并对其进行中序线索化 
template <class T>
ThreadBinaryTreeNode <T>*  InOrderThreading(ThreadBinaryTreeNode <T>* T) 
{

    ThreadBinaryTreeNode <T>* Thrt; 			//Thrt指向线索化之后的头结点
    Thrt = GetThrNode('', Link, Thread);   		//建头结点
    Thrt->AssignRight(Thrt);  					//右指针回指
    if (T == NULL)  Thrt->AssignLeft(Thrt);   	//若二叉树空, 则左指针回指
    else {
        Thrt->AssignLeft(T);   pre = Thrt;
        InThread(T, pre); 						//中序遍历进行中序线索化
        pre->AssignRight(Thrt);  
        pre->AssignRTag(Thread);
        Thrt->AssignRight(pre);  				//最后一个结点线索化
    }
    return Thrt;
} 
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
