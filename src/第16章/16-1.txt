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
　　
