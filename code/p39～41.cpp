template <class T> 
DoubleList<T>::DoubleList(void)    	//构造函数
{
    head = new DoubleNode<T>();    	//头指针指向头结点
    head->right = head;
    head->left = head;            
    LeftEnd= RightEnd=head;       	//size的初值为0
}

template <class T>
DoubleList<T>::~DoubleList(void)   	//析构函数
{ 
    DoubleNode<T> *p, *q;
    p = LeftEnd;                   	//p指向第一个结点
    while (p != NULL) {            	//循环释放结点空间直至初始状态
        q = p;
        p = p->right;
        delete q;
    }
    LeftEnd= RightEnd= NULL;
}

template <class T>
int DoubleList<T>::ListSize(void) const   //取当前数据元素个数并返回
{
    DoubleNode<T> *p;
    int size;
    p = LeftEnd->right;          	//p指向第一个结点
    while (p != LeftEnd) {         	//循环计数
        size++;
        p = p->right;
    }
    return size;
}

//在第i个结点后插入一个元素值为item的新结点
//参数i的取值范围为：0<=i<=ListSize()
template <class T>
void DoubleList<T>::Insert(const T& item, int i) 
{
    if (i < 0 || i > ListSize()){
        cout << "参数i越界出错!"  << endl;
        exit(0);
    }

    DoubleNode<T> *p = LeftEnd ->right;   	//p指向第一个数据元素结点
    int j = 0;                           	//从0开始计数
    while (p != LeftEnd && j < i) {        	//寻找第i个结点
        p = p->right;
        j++;
    }

    //构造新结点p, p的data域值为item, right域值为 p->right
    DoubleNode<T> *q = new DoubleNode<T>(item, p->left->right, p->left);

    p->left->right = q;             	//新结点插入第i个结点前
    p->left = q;                    	//新结点插入第i个结点前
    if (i== ListSize())  RightEnd=q;  	//若新结点为最后结点
}

//删除第i个数据元素并返回, 参数i的取值范围为：0≤i≤ListSize()-1
//被删元素通过x返回
template <class T>
T DoubleList<T>::Delete(int i, T& x)        
{
    if (ListSize() == 0) {
        cout << "链表已空无元素可删!" << endl;
        exit(0);
    }

    if (i < 0 || i > ListSize()-1) {
        cout << "参数i越界出错!" << endl;
        exit(0);
    }

    
    DoubleNode<T> *p = LeftEnd ->right;   	//p指向第一个数据元素结点
    int j = 0;                            	//从0开始计数
    while (p != LeftEnd  && j < i) {       	//寻找第i个结点
        p = p->right;
        j++;
    }
    if  (ListSize()==1) RightEnd = LeftEnd;	//只有1个结点时
    p->left->right = p->right;          	//第i个结点脱链
    p->right->left = p->left;           	//第i个结点脱链
    T x = p->data;
    delete p;                              	//释放第i个结点空间 
    return x;                              	//返回第i个结点的data域值
}

//取第i个数据元素并返回, 参数i的取值范围为：0<=i<=ListSize()-1
template <class T>
T DoubleList<T>:: Find(int i, T& x)       
{
    if (i < 0 || i > ListSize()-1) {
        cout << "参数i越界出错!" << endl;
        exit(0);
    }

    DoubleNode<T> *p = LeftEnd ->right;  	//p指向第一个数据元素结点
    int j = 0;                           	//从0开始计数
    while (p != LeftEnd && j < i) {        	//寻找第i个结点
        p = p->right;
        j++;
    }
    x= p->data;
}
