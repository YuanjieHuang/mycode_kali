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
