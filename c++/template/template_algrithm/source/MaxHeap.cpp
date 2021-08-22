template<class T>
void MaxHeap<T>::SiftDown(int left)
{
	//准备
	int i=left;		//标识父结点
	int j=2*i+1;	//标识键较小的子结点		
	T	temp=heapArray[i];	//保存父结点
	//过筛
	while (j < CurrentSize) {
		if ((j < CurrentSize) && (heapArray[j] < heapArray[j+1]))
			j++;		//j指向右子结点
		if (temp < heapArray[j]) {

			heapArray[i] = heapArray[j];
			i = j;
			j = 2 * j + 1;	//向下继续
		}
		else break;
	}
	heapArray[i] = temp;
}
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
