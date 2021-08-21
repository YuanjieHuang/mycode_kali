template <class Comparable>
class RedBlackTree;

template <class Comparable>
class RedBlackNode  {
    Comparable    element;
    RedBlackNode *left;
    RedBlackNode *right;
    int  color;

    //c = 1初始置为黑色
    RedBlackNode(const Comparable & theElement = Comparable(),
                 RedBlackNode *lt = NULL, RedBlackNode *rt = NULL,
                 int c = 1 )： element(theElement), left(lt), right(rt), color(c){}
    RedBlackNode Grandparent(RedBlackNode  n);
    RedBlackNode Uncle(RedBlackNode  n);
    friend class RedBlackTree<Comparable>;
};

template <class Comparable>
class RedBlackTree  {
public：
    explicit RedBlackTree(const Comparable & negInf);
    RedBlackTree(const RedBlackTree & rhs);
    ~RedBlackTree();

    const Comparable & findMin() const;
    const Comparable & findMax() const;
    const Comparable & find(const Comparable & x) const;
    bool isEmpty() const;
    void printTree() const;

    void makeEmpty();
    void insert(const Comparable & x);
    void remove(const Comparable & x);

    enum { RED, BLACK };

    const RedBlackTree & operator=(const RedBlackTree & rhs);
private：
    RedBlackNode<Comparable> *header;
    const Comparable ITEM_NOT_FOUND;
    RedBlackNode<Comparable> *nullNode;

    //插入及相关算法中使用
    RedBlackNode<Comparable> *current;
    RedBlackNode<Comparable> *parent;
    RedBlackNode<Comparable> *grand;
    RedBlackNode<Comparable> *great;

    //以下方法一般用递归实现
    void reclaimMemory(RedBlackNode<Comparable> *t) const;
    void printTree(RedBlackNode<Comparable> *t) const;
    RedBlackNode<Comparable> * clone(RedBlackNode<Comparable> * t) const;

    //红黑树的操纵方法
    void handleReorient(const Comparable & item );
    RedBlackNode<Comparable> * rotate(const Comparable & item,
                            RedBlackNode<Comparable> *parent) const;
    void rotateWithLeftChild(RedBlackNode<Comparable> * & k2) const;
    void rotateWithRightChild(RedBlackNode<Comparable> * & k1) const;
};

