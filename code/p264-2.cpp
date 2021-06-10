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
