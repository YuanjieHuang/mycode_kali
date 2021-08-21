template <class T>
struct PNode {
    T   data;
    int  parent; //双亲的下标
};

template <class T>
class PTree { 
protected:
    PNode<T>  nodes[MAX_TREE_SIZE];
    int n;  //结点数
public:
    PTree(){ n=0; }
    PNode<T> operator[](int i)
    { return nodes[i]; }
    PNode<T> GetNodes(int i)const
    { return nodes[i]; }
    int PTreeSize()
    { return n;}
    ...
};
