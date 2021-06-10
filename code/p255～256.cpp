template <class Type>
class Node {
    friend class dataList<Type>;
public：
    Node (const Type & value) ： key(value) {}
    Type getKey() const { return key; }
    void setKey(Type k) { key = k; }
private：
    Type  key;						
    ...
};

template <class Type>
class dataList {
public：
    dataList (int sz = 10):ArraySize(sz),Element(new Node <Type > [sz]) {}
    virtual ~dataList() { delete [] Element; }
    friend ostream &operator<<(ostream & OutStream,
                               const dataList<Type> & OutList);
                               dataList<Type> & InList);
    friend istream & operator>>(istream & InStream,
protected：
    Type *Element;					
    int ArraySize, CurrentSize;
};

template<class Elem>
class SSTable:class dataList  {  //静态查找表

public：
    //若静态查找表中存在键和key相等的元素, 则返回指向该元素的指针,否则返回"空"指针
    virtual Elem *Search(KeyType key);
    //按某种次序对静态查找表中每个元素调用函数visit()一次且仅一次
    virtual void Traverse(void visit(Elem& item));
};

template<class Elem>
class SqSTable：public SSTable  {	//顺序查找表

private：
    SqList<Elem> ST;
public：
    SqSTable(int size);      //构造函数
    SqSTable(SqSTable ra);   //复制构造函数
    //构造一个含size个元素的静态查找表, 其元素值由elemVal给出
    SqSTable(int size, const Elem * elemVal);
    ~SqSTable(void)  {};  //析构函数
    //若顺序查找表中存在其键和key相等的数据元素, 则返回指向该元素的指针,否则返回"空指针"
    virtual Elem *Search(KeyType key);
    //对顺序查找表中每个元素, 依次顺序调用函数visit一次, 并且仅调用一次
    virtual void Traverse(void visit(Elem& item));
};
