//交换线性选择排序, Array[]为待排序数组, n为数组长度
template <class Record,class Compare>
void StraightSelectSorter<Record,Compare>::Sort(Record R[], int n) 
{ 
	for (int i = 0; i < n-1; i++) {	//依次选出第i小的记录, 即剩余记录中最小的那个
	
        int Smallest = i;				//首先假设记录i就是最小的
        for (int j = i + 1; j < n; j++)	//开始向后扫描所有剩余记录
            if (Compare::lt(R[j], R[Smallest]))
                Smallest = j;	//如果发现更小的记录, 记录它的位置
        swap(R[i], R[Smallest]);	//将第i小的记录放在数组中第i个位置
	}
}
