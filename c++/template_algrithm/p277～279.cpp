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
