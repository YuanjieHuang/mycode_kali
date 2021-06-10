//表明结点平衡因子的常量
const int leftheavy = -1;
const int balanced = 0;
const int rightheavy = 1;

template <class T>
class AVLTree;

template <class T>
class AVLTreeNode  {
protected：
	//指向结点左右孩子的指针
	AVLTreeNode<T> *left;
	AVLTreeNode<T> *right;
private：
	//AVLTreeNode所需的附加数据成员
	int balanceFactor;
public：
	//公有成员, 允许外部修改的数据值
	T data;
	
	//构造函数
	AVLTreeNode(const T& item, AVLTreeNode<T> *lptr = NULL,
	AVLTreeNode<T> *rptr = NULL, int balfac = 0);
	
	//访问指针域的函数
	AVLTreeNode<T>* Left(void) const { return left; };
	AVLTreeNode<T>* Right(void) const { return right; };
	
	//访问新数据域的方法
	int GetBalanceFactor(void);
	
	friend class AVLTree<T>;
};

template <class T>
AVLTreeNode<T>::AVLTreeNode(const T& item, AVLTreeNode<T> *lptr, 
                            AVLTreeNode<T> *rptr, int balfac)：data(item), 
                            left(lptr), right(rptr), balanceFactor(balfac)
{}

template <class T>
int AVLTreeNode<T>::GetBalanceFactor(void)
{
    return balanceFactor;
}

template <class T>
class AVLTree  {
private：
	//指向树根及当前结点的指针
	AVLTreeNode<T> *root;
	AVLTreeNode<T> *current;
	
	//树中数据项个数
	int size;
	
	//用于复制构造函数及赋值运算符
	AVLTreeNode<T> *CopyTree(AVLTreeNode<T> *t);
	
	//用于析构函数,赋值运算符及ClearList方法
	void DeleteTree(AVLTreeNode<T> *t);
	
	//在函数Find和Delete中用来定位结点及其双亲在树中的位置
	AVLTreeNode<T> *FindNode(const T& item, AVLTreeNode<T>* & parent) const;
	
	//供Insert和Delete方法在结点加入子树或从子树中删除时重建AVL树
	void SingleRotateLeft(AVLTreeNode<T>* &p);
	void SingleRotateRight(AVLTreeNode<T>* &p);
	void DoubleRotateLeft(AVLTreeNode<T>* &p);
	void DoubleRotateRight(AVLTreeNode<T>* &p);
	void UpdateLeftTree(AVLTreeNode<T>* &tree,	bool &reviseBalanceFactor);
	void UpdateRightTree(AVLTreeNode<T>* &tree, bool &reviseBalanceFactor);
	
	//AVL树的Insert和Delete方法
	void AVLInsert(AVLTreeNode<T>* &tree,AVLTreeNode<T>* newNode,
	               bool &reviseBalanceFactor); 
	AVLTree<T>::AVLDelete(T val,AVLTreeNode<T>* &waste,int &flag);
	AVLTree<T>::removeLeftmostElement(AVLTreeNode<T>* &childptr,int &flag);
public：
	//构造函数,析构函数
	AVLTree(void);
	AVLTree(const AVLTree<T>& tree);
	~AVLTree(void);
	
	//赋值运算符
	AVLTree<T>& operator=(const AVLTree<T>& tree);
	
	//标准的表处理函数
	bool Find(T& item);
	void Insert(const T& item);
	void Delete(const T& item); 
	void ClearList(void);
	bool ListEmpty(void) const;
	int ListSize(void) const;
	
	//树的特殊方法
	void Update(const T& item);
	AVLTreeNode<T> *GetRoot(void) const;
};
