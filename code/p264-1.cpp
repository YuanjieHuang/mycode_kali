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
