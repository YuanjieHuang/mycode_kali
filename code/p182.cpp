template <class T>
class ThreadBinaryTree {
private:
    ThreadBinaryTreeNode<T>* root;				//根结点指针
public:
    ThreadBinaryTree(){ root=NULL; };			//构造函数
    virtual ~ThreadBinaryTree(){ DeleteTree(root); };
    ThreadBinaryTreeNode<T>* getRoot(){ return root; };//返回根结点指针
    //以element作为根结点, leftTree作为树的左子树,
    //rightTree作为树的右子树, 构造一棵新的二叉树
    void CreateTree(const T& elem, ThreadBinaryTree<T>& leftTree,ThreadBinaryTree<T>&
                        rightTree);
    //删除二叉树或其子树
    void DeleteTree(ThreadBinaryTreeNode<T>* root);
    //中序线索化二叉树
    void InThread(ThreadBinaryTreeNode<T>* root);
    //递归中序线索化二叉树
    void InThread(ThreadBinaryTreeNode<T>* root,
    ThreadBinaryTreeNode <T> * &pre);
    //中序遍历
    void InOrder(ThreadBinaryTreeNode<T>* root, void Visit(T& item));
    //在中序线索树中找指定结点在中序下的后继
    ThreadBinaryTreeNode<T>* FindNextinInorderTree(ThreadBinaryTreeNode<T>* pointer);
    //在中序线索树中找指定结点在中序下的前驱
    ThreadBinaryTreeNode<T>* FindPriorinInorderTree(ThreadBinaryTreeNode<T>* pointer);
    //在中序线索树中找指定结点在先序下的后继
    ThreadBinaryTreeNode<T>* FindPreNextinInorderTree(ThreadBinaryTreeNode<T>* pointer);
    //在中序线索树中找指定结点在后序下的前驱
    ThreadBinaryTreeNode<T>* FindPostPriorinInorderTree(ThreadBinaryTreeNode<T>*
                                                           	pointer);
    //往中序线索树里插入一个新结点
    void InsertNode(ThreadBinaryTreeNode<T>*pointer,
                    ThreadBinaryTreeNode<T>* newpointer);
};
