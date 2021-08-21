template <class T>
class seqList {
private:
    int size;							//数组规模
    int current_size;						//容器中的对象个数
    T *storage;							//数组的起始地址
    void doubleSpace();						//将数组容量扩大一倍

public:
    seqList(int s = 10):size(s) {storage = new T[size]; current_size = 0;}
    ～seqList() {delete [] storage;}
    void push_back(const T &x)					//在容器尾添加对象
    {   if (size == current_size) doubleSpace();
        storage[current_size++] = x;
      }
    void pop_back( )						//删除容器尾的对象
    { if (current_size == 0)  cerr << "这是一个空容器\n"; else --current_size;  }
    T &operator[](int i) { return storage[i]; }	//下标运算符重载

    class Itr {							//迭代器类的定义
        T *pos;							//指向容器中的某一对象
    public:
        Itr(T *obj = NULL) {pos = obj;}
        Itr &operator++() { ++pos;  return *this;} 			//指向容器中的下一对象
        T &operator*() { return *pos;}				//取迭代器指向的对象值
        bool operator!=(const Itr &p) {return pos != p.pos;}	//比较两迭代器对象是否相同

        friend class seqList<T>;
    };	

    Itr begin() {return Itr(storage);}			//返回指向第一个对象的迭代器
    Itr end() { return Itr(storage + current_size); }	//返回指向最后一个对象的迭代器
    void insert(Itr &p, const T &x) ;			//在迭代器指定的位置上插入对象
    void erase(const Itr &p);				//删除迭代器指定的位置中的对象
};

template <class T>
void seqList<T>::doubleSpace() 
{   T *tmp = storage;

    size *= 2;
    storage = new T[size];
    for (int i = 0; i < current_size; ++i) storage[i] = tmp[i];
    delete [] tmp;
}

template <class T>
void seqList<T>::insert( Itr &p, const T &x) 
{   T *q;

    if (size == current_size) {
        int offset = p.pos - storage;
        doubleSpace(); 
        p.pos = storage + offset;		//迭代器指回新空间中的相应对象
    }
    q = storage + current_size;

    while (q > p.pos) { *q = *(q-1); --q;}	//迭代器指出的对象后的所有对象后移一个位置
 
    *p.pos = x;
    ++current_size;
}


template <class T>
void seqList<T>::erase(const Itr &p) 
{   T *q =p.pos ;

    --current_size;
    while (q < storage + current_size)  { *q = *(q+1);   ++q;}
}


　　//文件名：16-3.cpp
　　//顺序容器的使用示例
　　int main()
　　{   seqList<int>  sq(10);		//定义一个存放整型对象的顺序容器，初始容量为10个对象
　　    seqList<int>::Itr itr1;	//定义一个对应的迭代器类的对象
　　 
　　    for (int i = 0; i < 10; ++i) sq.push_back(2 * i + 1);
　　
　　    cout << "用下标运算符输出:\n";
　　    for (i = 0; i < 10;  ++i) cout << sq[i] << '\t';
　　
　　    cout << "用迭代器输出:\n";
　　    for (itr1 = sq.begin() ; itr1 != sq.end();  ++itr1)  cout << *itr1 << '\t';
　　
　　    //插入0,2,4,6,8,10,12,14,16,18
　　    for (itr1 = sq.begin(), i = 0 ; i < 20; ++itr1, ++itr1, i += 2) sq.insert(itr1, i);
　　
　　    cout << "插入0,2,4,6,8,10,12,14,16,18后:\n";
　　    for (itr1 = sq.begin() ; itr1 != sq.end();  ++itr1)  cout << *itr1 << '\t';
　　
　　    //删除0,2,4,6,8,10,12,14,16,18
　　    for (itr1 = sq.begin(); itr1 != sq.end(); ++itr1)  sq.erase(itr1);
　　
　　    cout << "删除0,2,4,6,8,10,12,14,16,18后:\n";
　　    for (itr1 = sq.begin() ; itr1 != sq.end();  ++itr1)  cout << *itr1 << '\t';
　　
　　    return 0;
　　}
　　
　　template <class elemType>
　　class linkList {
　　private:
　　    struct Node {
　　        elemType  data;
　　        Node  *next;
　　
　　        Node(const elemType &x, Node  *N = NULL) { data = x; next = N;}
　　        Node():next(NULL) {}
　　    ～Node() {}
　　    };
　　
　　    Node  *head; 
　　    void makeEmpty();
　　
　　public:
　　    linkList()   { head = new Node;   }
　　    ～linkList()  { makeEmpty();  delete head;}
　　    class Itr {
　　    private:  Node  *current; //用指向Node的指针表示对象位置
　　    public:
　　        Itr(Node *p) {current = p;}
　　        bool operator()() const  { return current != NULL; }
　　        bool isHead() const {return current == head;}
　　        const elemType &operator*() const {return current->data;}
　　        void operator++() {current = current->next; }
　　
　　        friend class linkList<elemType>;
　　    }; 
　　
　　    void insert(Itr &p, const elemType &x) 
　　    {   p.current->next = new node(x, p.current->next);
　　        p.current = p.current->next; 
　　    }
　　    void erase(Itr &p) 
　　    {   Node  *q = p.current->next;
　　        if (!q) return;
　　        p.current->next = q->next; delete q;
　　    }
　　    Itr begin() {return Itr(head->next);}
　　    Itr GetHead() {return Itr(head);}
　　};
　　
　　template <class elemType>
　　void linkList<elemType>::makeEmpty()
　　{   Node  *p, *q;
　　
　　    p = head->next;
　　    head->next = NULL; //将链表设为空链表
　　
　　    while ( p != NULL) { q=p->next; delete p; p = q;} //回收链表中的所有结点
　　}
　　
　　//文件名：16-6.cpp
　　//listLink的使用示例
　　int main()
　　{   linkList<int>  lq;			//定义一个整型的容器lq
　　    linkList<int>::Itr itr1 = lq.GetHead();	//定义一个迭代器，并让它指向lq的头结点
　　 
　　    for (int i = 0; i < 10; ++i) lq.insert(itr1, 2 * i + 1);
　　
　　    cout << "用迭代器输出:\n";
　　    for (itr1 = lq.begin() ; itr1();  ++itr1)  cout << *itr1 << '\t';
　　
　　    //插入0,2,4,6,8,10,12,14,16,18
　　    for (itr1 = lq.GetHead(), i = 0 ; i < 20;  ++itr1, i += 2) lq.insert(itr1, i);
　　
　　    cout << "插入0,2,4,6,8,10,12,14,16,18后:\n";
　　    for (itr1 = lq.begin() ; itr1();  ++itr1) cout << *itr1 << '\t';
　　
　　    //删除0,2,4,6,8,10,12,14,16,18
　　    for (itr1 = lq.GetHead(); itr1(); ++itr1) lq.erase(itr1);
　　
　　    cout << "删除0,2,4,6,8,10,12,14,16,18后:\n";
　　    for (itr1 = lq.begin() ; itr1();  ++itr1) cout << *itr1 << '\t';
　　
　　    return 0;
　　}
　　
