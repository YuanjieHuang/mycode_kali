#include "DoubleNode.h"
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

#include <iostream.h>

//双向循环链表结点的构造函数
DoubleNode(Type value, DoubleNode<Type> * lLink, DoubleNode<Type> *rLink) :
	data(value), freq(0), left(lLink), right(rLink) {}
DoubleNode(Type value) : 
	data(value), freq(0),left(NULL), right(NULL) {}

template <class Type> 
DoubleList<Type> :: DoubleList (Type uniqueVal) 
{
	first = new DoubleNode<Type>(uniqueVal);
	first->right= first->left = first;		//创建表头结点
	current = NULL;
	cout << "开始建立双向循环链表：\n";
	Type value;	 cin >> value;
	while (value != uniqueVal) {		//每次新结点插入在表头结点后面
   		first->right = new DoubleNode<Type>(value, first, first->right);
   		cin >> value;
	}	
}

template <class Type>
void DoubleList<Type> :: Locate (Type & x) 
{
	DoubleNode<Type> *p = first->right;
	while (p != first && p->data != x) p = p->right;
	if (p != first) {						//链表中存在x
	  	p->freq++;						//该结点的访问频度加1
		current = p;						//从链表中摘下这个结点
		current->left->right = current->right;
		current->right->left = current->left;
		p = current->left;					//寻找从新插入的位置
		while (p != first && current->freq > p->freq)
			p = p->left;
		current->right = p->right;			//插入在p之后
		current->left = p;
		p->right->left = current;
		p->right = current;
	}
	else cout << "Sorry. Not find!\n";		//没找到
}

