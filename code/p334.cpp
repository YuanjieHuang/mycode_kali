template<class T>
void MaxHeap<T>::MoveMax()
{
	if(CurrentSize==0) {		//堆为空
		
		return;
	}
	else {

		T temp = heapArray[0];	//取堆顶元素
		heapArray[0] = heapArray[CurrentSize-1];	//堆末元素上升至堆顶
		CurrentSize--;
		SiftDown(0);			//从堆顶开始筛选
		heapArray[CurrentSize] = temp;
	}
	return;
}
