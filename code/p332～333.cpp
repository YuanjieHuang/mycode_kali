template <class Record,class Compare>
class HeapSorter:public Sorter<Record,Compare> {
public:
	void Sort(Record R[],int n);
};

//堆排序, R[]为待排序数组, n为数组长度
template <class Record, class Compare>
void HeapSorter<Record, Compare>::Sort(Record R[], int n) 
{ 
	MaxHeap<Record> max_heap = MaxHeap<Record>(R, n, n);	//建堆
	for (int i=0; i<n; i++)		 //依次找出剩余记录中的最大记录, 即堆顶
		max_heap.MoveMax();	
}

