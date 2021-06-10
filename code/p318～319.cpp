template <class Record,class Compare>
void TableInsertSort(Record a[], int N)
{

	int* next = new int[N]; 
	int head = 0, pre, cur, i; 
	next[0] = -1;
	for (i = 1; i < N; i++) {
		if Compare::gt(a[head], a[i])) { //没设表头, 因此需要此判断
			next[i] = head; head = i; 
		} 
		else {

			for (cur = head; cur != -1 && Compare::lteq(a[cur],a[i]); cur = next[cur])
				pre = cur;
			next[pre] = i; 
			next[i] = cur;
		}
	}
	cur = head;		//重排序列
	for (i = 0; i < N; i++) {

		while (cur < i)  cur = next[cur];
		pre = next[cur];
		if (cur != i) {

			swap(a[i], a[cur]); 
			next[cur] = next[i]; 
			next[i] = cur;
		}
		cur = pre;
	}
	delete [] next;
}
