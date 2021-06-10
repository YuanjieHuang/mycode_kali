template <class T>
class MaxHeap {

private:
	T* heapArray;		//存放堆数据的数组
	int CurrentSize;	//当前堆中元素数目
	int MaxSize;		//堆所能容纳的最大元素数目
public:
	MaxHeap(T* R, int num, int max) {
		HeapArray = R;
		CurrentSize = num;
		MaxSize = max;
		BuildHeap();
	};
	virtual ~MaxHeap(){};	//析构函数
	void BuildHeap() {
		for (int i = CurrentSize/2-1; i >= 0; i--) 
			SiftDown(i); 
	};
	bool isLeaf(int pos) const{
		return (pos >= CurrentSize/2) && (pos < CurrentSize);	//如果是叶结点,返回TRUE
	};	 
	int leftchild(int pos) const{
		return 2*pos+1;				//返回左孩子位置
	};		                        
	int rightchild(int pos) const{
		return 2*pos+2;				//返回右孩子位置
	};		                                	
	int parent(int pos) const{
		return (pos-1)/2;
	};				                			//返回父结点位置
	bool Remove(int pos, T& node);			//删除给定下标的元素
	void SiftDown(int left);				//筛选法函数,参数left表示开始处理的数组下标
	void SiftUp(int position);			 	//从position向上开始调整, 使序列成为堆
	bool Insert(const T& newNode);			//向堆中插入新元素newNode
	void MoveMax();						//从堆顶移动最大值到尾部
	T& RemoveMax();						//从堆顶删除最大值
};

