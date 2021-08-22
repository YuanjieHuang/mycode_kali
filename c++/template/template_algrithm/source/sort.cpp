//基本排序类
template <class Record,class Compare>
class Sorter {
protected:
	static void swap(Record Array[], int i, int j);	//交换数组中的两条记录
public:
	void Sort(Record Array[],int n);				//对数组Array进行排序
	void PrintArray(Record array[], int n);			//输出数组内容
};

//交换数组中的两条记录
template <class Record,class Compare>
void Sorter<Record,Compare>::swap(Record Array[], int i, int j)
{
	Record TempRecord = Array[i];
	Array[i] = Array[j];
	Array[j] = TempRecord;
}

//输出数组内容
template <class Record,class Compare>
void Sorter<Record,Compare>::PrintArray(Record Array[], int n)
{
	for (int i = 0; i < n; i++)
		cout << Array[i] << " ";
	cout << endl;
}  
//直接插入排序, R[]为待排序数组, n为数组长度
template <class Record, class Compare>
void StraightInsertSorter<Record, Compare>::Sort(Record  R[], int n) 
{ 
	//依次插入第I条记录
	for (int i = 2; I <= n; i++) {   
		R[0] = R[i];
		//依次与前面的记录进行比较, 如果发现比它小的记录就交换
		for (int j = i-1; Compare::lt(R[0], R[j]); j--) {

			R[j+1] = R[j];
		}
		R[j+1] = R[0];
	}
}
//二分插入排序, R[]为待排序数组, n为数组长度
template <class Record,class Compare>
void BinaryInsertSorter<Record,Compare>::Sort(Record R[], int n) 
{ 
	Record TempRecord;			//用来保存当前待插入纪录的临时变量
	int left, right, middle;		//记录已排好序序列的左,右及中间位置
	for (int i = 1; i < n; i++) {	//插入第i个记录
	          
		TempRecord = R[i];			//将当前待插入记录保存在临时变量中
		left = 0; right = i-1;		//记录已排好序序列的左右位置
		while (left <= right) {	//开始查找待插入记录的正确位置
		
			middle = (left + right)/2;		//记录中间位置
			//如果待插入记录比中间记录小就在左一半中查找, 否则在右一半中查找
			if (Compare::lt(TempRecord, R[middle]))
				right = middle - 1;
			else left = middle + 1;
		}
		//将前面所有大于当前待插入记录的记录后移
		for(int j = i-1; j >= left; j--)
			R[j+1] = R[j];
		R[left] = TempRecord;	//将待插入记录回填到正确位置
	}
}	

//冒泡排序, Array[]为待排序数组, n为数组长度
template <class Record,class Compare>
void BubbleSorter<Record,Compare>::Sort(Record Array[], int n) 
{   
	Boolean exchange；					//交换标志
	for (int i = 1; i < n; i++) {		//第i个记录起泡
	    exchange = FALSE；				//本趟排序开始前, 交换标志应为假
		for (int j = n-1; j >= i; j--)	//依次比较相邻记录
			if (Compare ::lt(Array[j], Array[j-1])) {	//如果逆置, 就交换
			   swap(Array, j, j-1); 
				exchange = TRUE；		 //发生了交换, 故将交换标志置为真
			}
		if (!exchange) //本趟排序未发生交换, 提前终止算法
			return;
	} 
}

template <class Record,class Compare>
void Bubble_Sort2(Record a[], int n)
{
    int low = 0,high = n-1;
    int change = 1;
    int i, temp;
    while (low < high&&change) {
        change = 0;
        for (i = low; i < high; i++)
            if Compare::gt(a[i], a[i+1])) {
                
                swap(a[i], a[i+1]);		//a[i]与a[i+1]交换
                change=1;
            }
        high--;
        for (i = high; i > low; i--)
            if Compare::lt(a[i], a[i-1])) {
                
                swap(a[i],a[i-1]);		//a[i]与a[i-1]交换
                change=1;
            }
        low++;
    }
}
