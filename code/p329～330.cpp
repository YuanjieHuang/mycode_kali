//胜者树结点的类定义
template <class Type> 
class DataNode {		
public:
	Type data;		//数据值
	int index;		//树中的结点号, 即在完全二叉树顺序存储中的下标
	int active;		//是否参选的标志, 1表示参选; 0表示不再参选
}

//建立树的顺序存储数组tree, 将数组a[]中的元素复制到胜者树中
//对它们进行排序, 并把结果返送回数组中, n是待排序元素个数
template <class Type> 
void TournamentSort (Type a[], int n) 
{
	DataNode<Type> *tree;	//胜者树结点数组
	DataNode<Type> item;
	//计算满足大于等于n的2的最小次幂的数: 树的底行大小n=7时它为8
	int bottomRowSize = PowerOfTwo(n);	
	//计算胜者树的大小: 内结点数+外结点数
	int TreeSize = 2 * bottomRowSize - 1;		
	int loadindex = bottomRowSize - 1;		//外结点开始位置
	tree = new DataNode<Type>[TreeSize];	//动态分配胜者树结点数组空间
	int j = 0;	//在数组a中取数据指针
	for (int i = loadindex; i < TreeSize; i++) {	//复制数组到树的外结点中
		tree[i].index = i;			//下标
		if (j < n) { tree[i].active = 1;  tree[i].data = a[j++]; }	//复制数据
		else tree[i].active = 0;	//后面的结点为空的外结点
	}
	i = loadindex;				//进行初始比较寻找最小的项
	while (i) {
		j = i;
		while (j < 2*i) {			//处理各对比赛者
			if (!tree[j+1].active || tree[j].data <= tree[j+1].data) 
				tree[(j-1)/2] = tree[j];	//胜者送入父结点
			else tree[(j-1)/2] = tree[j+1];
			j += 2;	//下一对参加比较的项
		}
		i = (i-1)/2;	//i退到双亲, 直到i=0为止
	}
	for (i = 0; i < n-1; i++) {			//处理其他n-1元素
		 a[i] = tree[0].data;				//当前最小元素送数组a
		 tree[tree[0].index].active = 0;	//该元素相应外结点不再比赛
		 UpdateTree (tree, tree[0].index);	//从该处向上修改
	}
	a[n-1] = tree[0].data;
}

//排序的调整算法：i是当前最小元素的下标, 即胜者, 从它开始向上调整
template <class Type> 
void UpdateTree (DataNode<Type> *tree, int i) 
{
	if (i %2 == 0) tree[(i-1)/2] = tree[i-1];		//i为偶数, 对手为左结点
	else tree[(i-1)/2] = tree[i+1];					//i为奇数, 对手为右结点
	//最小元素输出之后, 它的对手上升到父结点位置
	i = (i - 1)/2;					//i上升到父结点位置
	while (i) {
		  if (i%2 == 0) j = i - 1;		//确定i的对手是左结点还是右结点
		  else j = i + 1;
		  if (!tree[i].active || !tree[j].active)	//比赛对手中间有一个为空
			  if (tree[i].active ) tree[(i-1)/2] = tree[i];
			  else tree[(i-1)/2] = tree[j];			//非空者上升到父结点
		  else										//比赛对手都不为空 
			  if (tree[i].data < tree[j].data) tree[(i-1)/2] = tree[i];
			  else tree[(i-1)/2] = tree[j];			//胜者上升到父结点
		  i = (i - 1)/2;							//i上升到父结点
	}
}
