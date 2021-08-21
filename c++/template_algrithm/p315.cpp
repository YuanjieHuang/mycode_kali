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
