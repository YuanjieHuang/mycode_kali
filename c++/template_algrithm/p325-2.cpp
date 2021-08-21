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
