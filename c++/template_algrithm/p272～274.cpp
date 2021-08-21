template <class T>
void AVLTree<T>::SingleRotateLeft(AVLTreeNode<T>* &p)
{
	AVLTreeNode<T> *rc = p->right;
	
	p->balanceFactor = balanced;
	rc->balanceFactor = balanced;
	
	p->right = rc->left;
	rc->left = p;
	p = rc;
} 

//绕结点p顺时针旋转, 使lc成为新轴
template <class T>
void AVLTree<T>::SingleRotateRight(AVLTreeNode<T>* & p)
{
	//p的左子树“超重”, 将p的左子树给lc
	AVLTreeNode<T> *lc = p->left;
	
	//修改双亲结点及左孩子的平衡因子
	p->balanceFactor = balanced;
	lc->balanceFactor = balanced;
	
	//lc的右子树st应继续为lc右子树的一部分, 将它改为p的左子树
	p->left = lc->right;
	
	//旋转p使其为lc的右子树, lc成为新轴
	lc->right = p;
	p = lc;
}

template <class T>
void AVLTree<T>::DoubleRotateLeft(AVLTreeNode<T>* &p)
{
	AVLTreeNode<T> *rc, *np;
	
	rc = p->right;
	np = rc->left;
	if (np->balanceFactor == leftheavy)  {
		p->balanceFactor = balanced;
		rc->balanceFactor = leftheavy;
	}
	else if (np->balanceFactor == balanced)  {
		p->balanceFactor = balanced;
		rc->balanceFactor = balanced;
	}
	else  {
		p->balanceFactor = leftheavy;
		rc->balanceFactor = balanced;
	}
	np->balanceFactor = balanced;
	rc->left = np->right;
	np->right = rc;
	p->right = np->left;
	np->left = p;
	p = np;
}

//绕结点p双右旋
template <class T>
void AVLTree<T>::DoubleRotateRight(AVLTreeNode<T>* &p)
{
	AVLTreeNode<T> *lc, *np;   //被旋转的两个子树
	
	//在树中, 结点(lc)<结点(np)<结点(p)
	lc = p->Left();		//lc为双亲的左孩子
	np = lc->Right();		//np为lc的右孩子
	
	//修改 p, lc和np的平衡因子
	if (np->balanceFactor == rightheavy)  {
		p->balanceFactor = balanced;
		lc->balanceFactor = rightheavy;
	}
	else if (np->balanceFactor == balanced)  {
		p->balanceFactor = balanced;
		lc->balanceFactor = balanced;
	}
	else  {
		p->balanceFactor = rightheavy;
		lc->balanceFactor = balanced;
	}
	np->balanceFactor = balanced;
	
	//在np替代双亲p之前, 注意卸掉其老子树, 连上新子树
	lc->right = np->left;
	np->left = lc;
	p->left = np->right;
	np->right = p;
	p = np;
} 

template <class T>
void AVLTree<T>::UpdateLeftTree(AVLTreeNode<T>* &p, bool &reviseBalanceFactor)
{
	AVLTreeNode<T> *lc = p->left;	
	
	//左子树边偏重
	if (lc->balanceFactor == leftheavy)  {
		SingleRotateRight(p);		//需单旋转
		reviseBalanceFactor = false;
	}
	//右子树偏重
	else if (lc->balanceFactor == rightheavy)  {
		
		DoubleRotateRight(p);   //做一次双旋转
		reviseBalanceFactor = false;  //此时, 根结点平衡了
	}
}

template <class T>
void AVLTree<T>::UpdateRightTree(AVLTreeNode<T>* &p, bool &reviseBalanceFactor)
{
	AVLTreeNode<T> *rc = p->right;
	
	if (rc->balanceFactor == rightheavy)  {
		SingleRotateLeft(p);
		reviseBalanceFactor = false;
	}
	else if (rc->balanceFactor == leftheavy)  {
		DoubleRotateLeft(p);
		reviseBalanceFactor = false;
	}
}
