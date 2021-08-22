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
//在树中搜索数据项, 若找到, 则返回结点地址及指向其双亲的指针; 否则, 返回 NULL
template <class T>
AVLTreeNode<T> *AVLTree<T>：：FindNode(const T& item, AVLTreeNode<T>* & parent) const
{   
    AVLTreeNode<T> *t = root; //用指针t从根开始遍历树
    
    
    parent = NULL;   //根的双亲为NULL
    
    while (t != NULL)  {   //若子树为空, 则循环结束
        
        if (item == t->data)   //若找到键值, 则退出
            break;
        else  {
            //修改双亲指针, 并移到左子树或右子树
            parent = t;
            if (item < t->data) t = t->left;
            else t = t->right;
        }
    }
    
    return t; //返回指向结点的指针; 若没找到, 则返回NULL
}
template <class T>
void AVLTree<T>::AVLInsert(AVLTreeNode<T>* & tree, 
						     AVLTreeNode<T>* newNode, bool &reviseBalanceFactor)
{
	bool rebalanceCurrNode; //是否需修改结点的 balanceFactor 值的标志
	
	//扫描到空子树, 此时应插入新结点
	if (tree == NULL)  {
		tree = newNode; //更新双亲结点使其指向新结点     
		
		tree->balanceFactor = balanced; //将新结点的 balanceFactor 赋值为 0
		
		reviseBalanceFactor = true; //广播消息, balanceFactor 值被改变
	}
	//若新结点的数据值小于当前数据值, 则递归遍历左子树
	else if (newNode->data < tree->data)  {
		AVLInsert(tree->left, newNode, rebalanceCurrNode);
		
		//检查是否应修改balanceFactor值
		if (rebalanceCurrNode)  {
			//从左偏重的子树往左, 将违背AVL条件, 进行旋转（情况3） 
			if (tree->balanceFactor == leftheavy)
				UpdateLeftTree(tree,reviseBalanceFactor);         

			//从平衡结点往左, 往左子树增加结点, 满足AVL条件（情况1）
			else if (tree->balanceFactor == balanced)  {
				tree->balanceFactor = leftheavy;
				reviseBalanceFactor = true;
			}
			//从右偏重子树往左, 将产生平衡子树, 满足AVL条件（情况2）
			else  {
				tree->balanceFactor = balanced;
				reviseBalanceFactor = false;
			}
		}
		else	//不需平衡此结点, 也不用平衡上结点
			reviseBalanceFactor = false;
	}
	else  {		//否则, 递归遍历右子树
		AVLInsert(tree->right, newNode, rebalanceCurrNode);
		
		//检查是否应修改 balanceFactor值
		if (rebalanceCurrNode)  {
			//从左偏重子树往右, 将平衡结点, 满足AVL条件（情况2）
			if (tree->balanceFactor == leftheavy)  {
				//扫描右子树, 结点左偏重, 则将成为平衡结点
				tree->balanceFactor = balanced;     
				reviseBalanceFactor = false;
			}
			//从平衡子树往右, 将产生右偏重结点, 满足AVL条件（情况1）
			else if (tree->balanceFactor == balanced)  {
				//结点原为平衡, 将成为右偏重
				tree->balanceFactor = rightheavy;
				reviseBalanceFactor = true;
			}
				//从右偏重结点向右, 将违背AVL条件, 应进行旋转（情况3）
			else
				UpdateRightTree(tree, reviseBalanceFactor);
		}
		else
			reviseBalanceFactor = false;
	}
}

template <class T>
void AVLTree<T>::Insert(const T& item)
{
	AVLTreeNode<T> *treeRoot = root, *newNode; 	//定义指向AVL树结点的指针
	bool reviseBalanceFactor = false; 			//供AVLInsert重新平衡结点的标志
	newNode = new AVLTreeNode<T>(item,NULL,NULL);
	
	//调用递归函数实际插入元素
	AVLInsert(treeRoot, newNode, reviseBalanceFactor);
	
	//赋新值给基类中的数据成员
	root = treeRoot;
	current = newNode;
	size++;
}
template <class T>
AVLTree<T>::AVLDelete(T val,AVLTreeNode<T>* &waste, int &flag)
{
	if (val==data)  {
		waste = this;
		//当没有右子树的时候返回左子树
		if(Right() == NULL)  {
			flag=1;
			return Left();
		}
		//删除右子树中的最小结点
		int oldbf = Right()->balanceFactor;
		AVLTreeNode* newroot;
		//找到后返回已经平衡的AVL树的根指针
		right(Right()->removeLeftmostElement(newroot,flag));
		newroot->Left(Left());
		newroot->Right(Right());
		if ((flag == 1) && (balanceFactor == 1)) flag = 1;
		else flag = 0;
		if (flag == 1)  {
			newroot-> balanceFactor = balanceFactor --;
		}
		else newroot->balanceFactor = balanceFactor;
        //左子树的平衡
		AVLTreeNode<T>* rightchild=newroot->Right();
	    if (rightchild == NULL) balanceFactor--;
	    else if ((rightchild->balanceFactor != oldbf) && (rightchild->balanceFactor == 0))
		    balanceFactor--;
		if (balanceFactor<-1)  {
		    int newoldbf = newroot->Left()->balanceFactor;
	        if (newoldbf > 0)  {	//双旋转
    	            return newroot-> doubleLeftRotation();
			}
	        else  {		//单旋转
		        return newroot-> SingleRotateRight ();
           	}
		}
	    return newroot;
		
	}
	else if (val < data)  {	//从左子树中删除
		if(Left() == NULL) return this;
		//执行删除
		int oldbf=Left()->balanceFactor;
		left(Left()->remove(val, waste, flag));		//递归调用
        //调整左子树
        AVLTreeNode<T>* leftchild=Left();
	    //计算删除后的子树对当前的根结点的平衡因子的影响
	    if (leftchild == NULL) balanceFactor++;
	    else if ((leftchild->balanceFactor != oldbf) && (leftchild->balanceFactor == 0))
		    balanceFactor++;
	    if (balanceFactor > 1)  {		//失衡
		    //调整
		    int newoldbf = Right()->balanceFactor;
	        if (newoldbf < 0)  {		//双旋转
	           return DoubleRightRotation();
		    }
	        else  {	//单旋转
		        AVLTreeNode* temp = SingleRotateRight();
			    if (flag == 1)  balanceFactor++;
			    return temp;
		    }
		}
    		return this;
	}
	else  {
		//从右子树中删除
		if (Right() == NULL) return this;
		//执行删除
		int oldbf = Right()->balanceFactor;
		right(Right()->remove(val,waste,flag));//递归调用
		//调整右子树
		AVLTreeNode<T>* rightchild = Right();
		if (rightchild == NULL) balanceFactor--;
	    else if ((rightchild->balanceFactor != oldbf) && (rightchild->balanceFactor == 0))
		    balanceFactor--;
	    if (balanceFactor<-1)  {
		    int newoldbf = Left()->balanceFactor;
	        if (newoldbf>0)  {		//双旋转
    	            return DoubleLeftRotation();
		    }
	        else  {		//单旋转
			    AVLTreeNode* temp = SingleLeftRotateRight ();
			    if (flag == 1) balanceFactor--;
			    return temp;
		    }
		} 
	    return this;
	}
}

template <class T> 
AVLTree<T>::removeLeftmostElement(AVLTreeNode<T>* &childptr,int &flag)
{   //flag表示子树高度是否变化
	AVLTreeNode* leftchild = Left();
	//找到最小的值, 返回; 否则递归调用
	if (leftchild == NULL)  {
		childptr = this;
		flag = 1;
		return Right();
	}
	int oldbf = leftchild->balanceFactor;
	left(leftchild->removeLeftmostElement(childptr,flag));//递归调用
	//调整左子树平衡
	AVLTreeNode<T>* newleftchild=Left();
	//计算删除后的子树的高度变化
	if((newleftchild==NULL)&&(Right()==NULL)) flag=1;
	//计算删除后的子树对当前的根结点的平衡因子的影响
	if (newleftchild==NULL) balanceFactor++;
	else if((newleftchild->balanceFactor!=oldbf)&&(newleftchild->balanceFactor==0))
		balanceFactor++;
	if (balanceFactor > 1)  {		//失衡
		//调整
		int newoldbf=Right()->balanceFactor;
	    if (newoldbf<0)  {			//双旋转
	        return RL_doubleRotation();
		}
	    else  {						//单旋转
		    return RR_singleRotation();
		}
	}
	return this;
}
