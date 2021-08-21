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
