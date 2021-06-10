//双向链表的类定义
template <class T>
class DoubleNode {
friend DoubleList<T>;
private: 
    T data;
    DoubleNode<T> *left, *right;
public:
    //构造函数1,用于构造头结点
    DoubleNode (DoubleNode <T> *pRight = NULL, DoubleNode <T> *pLeft = NULL)
    { right = pRight; left = pLeft; }

    //构造函数2,用于构造其他结点
    DoubleNode (const T& item, DoubleNode <T> *pRight = NULL, 
                DoubleNode <T> *pLeft = NULL)
    { data = item; right = pRight; left = pLeft; }
//析构函数
    ~ DoubleNode (void){}	

};

template<class T>
class DoubleList {
public:
    Double() { LeftEnd = RightEnd = 0; }
    ~ Double ();
    int Length() const;
    bool Find(int i, T& x) const;
    int Search(const T& x) const;
    Double<T>& Delete(int i, T& x);
    Double<T>& Insert(const T& item, int i);
    void Output(ostream& out) const;
private:
    DoubleNode<T> *LeftEnd, *RightEnd;
};
