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
