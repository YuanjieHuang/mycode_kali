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

