//快速排序, R[]为待排序数组, i和j分别表示数组两端
template <class Record,class Compare>
void QuickSorter<Record,Compare>::Sort(Record R[], int left, int right) 
{
	if (right <= left) return; //如果子序列中包含0或1个记录,就不用排序
	int pivot = SelectPivot(left, right); //选择基准值
	swap(R, pivot, right); //将轴值放在数组末端
	pivot = Partition(R, left, right); //对剩余的记录进行分割, 分割后基准值已到达正确位置
	//对分割出的子序列进行递归快速排序
	Sort(R, left, pivot-1);  //对轴值左边的子序列进行递归快速排序
	Sort(R, pivot+1, right); //对轴值右边的子序列进行递归快速排序
}
template <class Record,class Compare>
int QuickSorter<Record,Compare>::Partition(Record R[], int low, int high) 
{
    Record pivot;			//存放基准值的临时变量
    int i = low-1;		//i为左指针,j为右指针
    int j = high+1;	
    int  pivot = SelectPivot(left, right);	//将基准值存放在临时变量中
    while (1)  {				//开始进行分割,i ,j开始向中间移动, 直到相遇
        //j指针向左移动, 直到找到一个小于等于基准值的记录
        while (Compare::gt(R[--j], R[pivot])) 
            //i指针向右移动, 直到找到一个大于等于基准值的记录
            while (Compare::lt(R[++i], R[pivot]))
                //如果i和j尚未相遇, 就交换
                if (i < j) swap(R[j], R[i]);
                else if  j <> high return j;
                else return j-1;
    }	
}

template <class Record,class Compare>
int QuickSorter<Record,Compare>::Partition(Record R[], int low, int high) 
{
	Record TempRecord;		//存放基准值的临时变量
	int i = low;				//i为左指针, j为右指针
	int j = high;	
	TempRecord = R[i];		//将基准值存放在临时变量中
	while (i != j)  {			//开始进行分割, i和j开始向中间移动, 直到相遇
		//j指针向左移动,直到找到一个小于等于基准值的记录
		while (Compare::gt(R[j], TempRecord) && (j > i))  j--;
		//如果i和j尚未相遇, 就将逆序元素换到左边的空闲位置
		if (i < j) {

			R[i] = R[j];
			i++;					//i指针向右移动一步
		}

		//i指针向右移动, 直到找到一个大于等于基准值的记录
		while (Compare::lt(R[i], TempRecord) && (j>i))i++;
		//如果i和j尚未相遇, 就将逆序元素换到右边的空闲位置
		if (i < j) {  

			R[j] = R[i];   
			j--;					//j指针向左移动一步
		}
	}	
	R[i] = TempRecord;		//把基准值回填到分界位置i上
	return i;					//返回分界位置i
}
