//二叉搜索树的删除方法1
template <class T>
void BiSearchTree<T>::DeleteNode(BiTreeNode<T>* pointer)
{   
	BiTreeNode<T>* temppointer=NULL;	
	if (!pointer) return;
	BiTreeNode<T>* parent = GetParent(root, pointer);
	if (pointer->leftchild()==NULL)  {		//被删结点无左子树吗
		if(parent == NULL)root = pointer->rightchild();	//被删除结点是根结点吗?
		else if(parent->leftchild() == pointer) parent->left = pointer->rightchild();
		else parent->right = pointer->rightchild();
		delete pointer;
		pointer = NULL;
		return;
	}
	else temppointer = pointer->leftchild();
	while (temppointer->rightchild() != NULL) 	//在左子树中找对称序的最后一个结点
		temppointer = temppointer->rightchild();
	temppointer->right=pointer->rightchild();//被删除结点的右子树作为temppointer的右子树
	if (parent == NULL) root = pointer->leftchild();	//被删除结点的左子树根代替被删除结点
	else if (parent->leftchild() == pointer)  parent->left = pointer->leftchild();
	else parent->right = pointer->leftchild();
	delete pointer;
	pointer = NULL;
	return;
}

//二叉搜索树的删除方法2
template <class T>
void BiSearchTree<T>::DeleteNodeEx(BiTreeNode<T>* pointer)
{   
	if (pointer == NULL) return;	//如果待删除结点不存在,返回
	BiTreeNode<T> * temppointer; 	//保存要替换上来的结点
	BiTreeNode<T> * tempparent = NULL; //保存要替换上来的结点的父结点
	BiTreeNode<T> * parent = GetParent(root ,pointer); 	//保存要删除结点的父结点

	//如果待删除结点的左子树为空, 就将它的右子树代替它即可
	if (pointer->leftchild() == NULL)  {
		//将右子树连到待删除结点的父结点的合适位置
		if (parent == NULL) root = pointer->rightchild();
		else if (parent->leftchild() == pointer) parent->left = pointer->rightchild();
		else parent->right = pointer->rightchild();
		delete pointer;
		pointer = NULL;
		return;
	}

	//当待删除结点左子树不为空, 就在左子树中寻找最大结点替换待删除结点
	temppointer = pointer->leftchild();
	while(temppointer->rightchild() != NULL)  {
		tempparent = temppointer;
		temppointer = temppointer->rightchild();
	}

	//删除替换结点
	if (tempparent == NULL) pointer->left = temppointer->leftchild();
	else tempparent->right = temppointer->leftchild();

	//用替换结点去替代真正的删除结点
	if (parent == NULL) root = temppointer;
	else if (parent->leftchild() == pointer) parent->left = temppointer;
	else parent->right = temppointer;

	temppointer->left = pointer->leftchild();
	temppointer->right = pointer->rightchild();

	delete pointer;
	pointer = NULL;
	return;
}

template <class T>
void BiSearchTree<T>::Insert(BiTreeNode<T>* &ptr, const T &k)
{
	if (ptr == NULL)
		ptr = new BiTreeNode<T>(k);	//生成并插入结点
	else if (item < ptr->data) 
		Insert(ptr->Left(), k);	//在左子树递归
	else if (item > ptr->data) 
		Insert(ptr->Right(), k);	//在右子树递归
}
template <class T>
BiTreeNode<T>* BiSearchTree<T>::Find(const T &k)
{ 
    if (root != NULL)  {
        BiTreeNode<T> *temp = root;
        while (temp != NULL)  {
            if (temp->data == k) return temp;	//查找成功

            if (temp->data < k) 
                temp = temp->Right();	//在右子树继续
            else 
                temp = temp->Left();	//在左子树继续
        }
    }
    return NULL;	　//查找失败
}
