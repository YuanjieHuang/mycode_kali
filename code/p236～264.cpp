template <class T> 
class BiSearchTree  {
    //输出流运算符重载
    friend istream &operator>>(istream &in, BiSearchTree<T>* &tree);
private：
    BiTreeNode<T> *root;	//根指针
    void Insert(BiTreeNode<T>* &ptr, const T &item);	//插入
    void Delete(BiTreeNode<T>* &ptr, const T &item);	//删除
    //先序、中序和后序遍历, 访问操作为Visit()函数
    void PreOrder(BiTreeNode<T>* &t, void (*Visit)(T item));
    void InOrder(BiTreeNode<T>* &t, void (*Visit)(T item));
    void PostOrder(BiTreeNode<T>* &t, void (*Visit)(T item));
public：
    //构造函数和析构函数
    BiSearchTree()：root(NULL){};	//注意：生成的二叉排序树不带根结点
    ~BiSearchTree(){};

    BiTreeNode<T>* Find(const T &item);	//查找
    void Insert(const T &item)			//插入
    { Insert(GetRoot(), item); }
    void Delete(const T &item)			//删除
    { Delete(GetRoot(), item); }

    BiTreeNode<T> * &GetRoot()	{ return root; }			//取树根
    BiTreeNode<T>* &LeftChild(BiTreeNode<T>* &current)	//取左孩子结点
    { return root != NULL ? current->Left() ： NULL; }
    BiTreeNode<T>* &RightChild(BiTreeNode<T>* &current)	//取右孩子结点
    { return root != NULL ? current->Right() ： NULL; }

    void PreOrder(void (*Visit)(T item))		//先序遍历
    { PreOrder(root, Visit); }
    void InOrder(void (*Visit)(T item))			//中序遍历
    { InOrder(root, Visit); }
    void PostOrder(void (*Visit)(T item))		//后序遍历
    { PostOrder(root, Visit); }
};
