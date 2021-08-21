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

