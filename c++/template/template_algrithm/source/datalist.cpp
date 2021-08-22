template <class Type> void datalist<Type>::count_sort() 
{
    int i, j;
    int *c = new datalist <Type>;			//c是存放计数排序结果的临时表
    for (i = 0; i < CurrentSize; i++) Vector[i].count = 0;	//初始化,计数值都为0
    for (i = 0; i < CurrentSize-1; i++)
        for (j = i+1; j < CurrentSize; j++)
            if (Vector[j].key < Vector[i].key) Vector[i].count++;
            else Vector[j].count++;        	//统计
    for (i = 0; i < CurrentSize; i++)		//在c->Vector[]中各就各位
        c->Vector[Vector[i].count] = Vector[i];
    //结果复制回当前表对象中
    for (i = 0; i < CurrentSize; i++) Vector[i] = c->Vector[i];
    delete c;
}
//a为输入, b为输出, l为元素个数, k为元素最大值 
void datalist<int>::count_sort2 ((int a[], int b[],int l,int k) {
    int* c = new int[k];
    memset(c, 0, k * sizeof(int));
    for (int j = 0; j < l; j++) c[a[j]]++;
    for (int j = 1; j < k; j++) c[j] += c[j - 1];
    for (int j = l - 1; j >= 0; j--) {
        b[c[a[j]] - 1] = a[j];
        c[a[j]]--;
    }
    delete []c;
}
