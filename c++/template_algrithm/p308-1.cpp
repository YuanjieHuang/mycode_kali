enum KindOfItem {Empty, Active, Deleted};

struct HashItem  {
	DataType data;
	KindOfItem info;

	HashItem(KindOfItem i = Empty):info(i){}
	HashItem(const DataType &D, KindOfItem i = Empty):data(D), info(i){}
	int operator ==(HashItem &a)
	{ return data == a.data; }
	int operator !=(HashItem &a)
	{ return data != a.data; }
};

class HashTable  {
private：
	HashItem *ht;		//散列表数组
	int TableSize;	//散列表的长度（即m）
	int currentSize;	//当前的表项个数
public：
	HashTable(int m) {		//构造函数
		TableSize = m;		//置散列表长度
		ht = new HashItem[TableSize];	//申请动态数组空间
		currentSize = 0;		//置初始的当前表项个数
	};										
	~HashTable(void)		//析构函数
	{ delete []ht; }

	int Find(const DataType &x)const;	//查找
	int Insert(const DataType &x);		//插入
	int Delete(const DataType &x);		//删除

	int IsIn(const DataType &x)	//是否已存在
	{ int i = Find(x); return i >= 0 ? 1： 0; }
	DataType GetValue(int i)const	//取数据元素
	{ return ht[i].data; }
};
