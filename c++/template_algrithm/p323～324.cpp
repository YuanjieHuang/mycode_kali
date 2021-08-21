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
