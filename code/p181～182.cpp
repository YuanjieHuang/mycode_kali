//线索链表的结点类
template <class T> class ThreadBinaryTree;
enum Tags{ Link,Thread };
template <class T>
class ThreadBinaryTreeNode {
    friend class ThreadBinaryTree<T>;
private: 
    Tags lTag,rTag;						//左右标志位
    ThreadBinaryTreeNode<T> *left,*right;	//线索或左右子树
    Telement;
public:
    ThreadBinaryTreeNode();
    //构造函数
    ThreadBinaryTreeNode(const T&):element(T),left(NULL),right(NULL),lTag(0),
         rTag(0){};
    //给定数据的左右指针的构造函数
    ThreadBinaryTreeNode(const T& ele,ThreadBinaryTreeNode<T>* l,
                         int leftTag, ThreadBinaryTreeNode<T>* r,int rightTag);
    T value() const{ return element; };						 		
    ThreadBinaryTreeNode<T>* leftchild()const { return left; };	
    ThreadBinaryTreeNode<T>* rightchild()const { return right; };
    void setValue(const T& type){ element=type; };
    virtual ~ThreadBinaryTreeNode(){};		//析构函数
    void AssignRTag(Tags tag) { rTag=tag; }
    void AssignLTag(Tags tag) { lTag=tag; }
    void AssignLeft(ThreadBinaryTreeNode<T>* pre){ left=pre };
    void AssignRight(ThreadBinaryTreeNode<T>* p){ right=p };
    bool p->RTG() { return (rTag == Thread) ? Thread:Link };
    bool p->LTG() { return (lTag == Thread) ? Thread:Link };
};
