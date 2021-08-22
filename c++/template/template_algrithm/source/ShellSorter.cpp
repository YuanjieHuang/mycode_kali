//谢尔排序, R[]为待排序数组, n为数组长度
template <class Record,class Compare>
void ShellSorter<Record,Compare>::Sort(Record R[], int n) 
{ 
	for (int delta = n/2; delta > 0; delta/=2)	//增量delta每次除以2递减
		for (int j = 0; j < delta; j++)   		//分别对delta个子序列进行插入排序
			ModifiedInsertSort(&R[j], n-j, delta);
}

//谢尔排序, R[]为待排序数组, n为数组长度
template <class Record,class int_intCompare>
void ShellSorter<Record,int_intCompare>::delta3Sort(Record R[], int n) 
{ 
	for (int delta = n/3; delta >= 3; delta/=3)		//增量delta每次除以3递减
		for (int j = 0; j < delta; j++)  			//分别对delta个子序列进行插入排序
			ModifiedInsertSort(&R[j], n-j, delta);
	ModifiedInsertSort(R, n, 1);
}

//针对变化的增量而修改的插入排序算法, 参数delta表示当前的增量
template <class Record,class Compare>
void ShellSorter<Record,Compare>::ModifiedInsertSort(Record R[],int n, int delta) 
{
	for (int i = delta; I < n; i+=delta) //对子序列中第i个记录排序
		for (int j = i; (j >= delta) && (Compare::lt(R[j], R[j-delta])); j-=delta) {
			swap(R, j, j-delta);
}
