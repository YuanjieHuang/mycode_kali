template <class Record, int order>
Error_code B_tree<Record, order>::insert(const Record &new_entry)
{
	Record median;
	B_node<Record, order> *right_branch, *new_root;
	Error_code result = push_down(root, new_entry, median, right_branch);
	if (result == overflow) { //整树伸高
		//创建一个结点
		new_root = new B_node<Record, order>;
		new_root->count = 1;
		new_root->data[0] = median;
		new_root->branch[0] = root;
		new_root->branch[1] = right_branch;
		root = new_root;
		result = success;
	}
	return result;
}

template <class Record, int order>
Error_code B_tree<Record, order> ::push_down(B_node<Record, order> *current,
                                             const Record &new_entry,Record &median,
                                             B_node<Record,
                                             order> * &right_branch)
{
	Error_code result;
	int position;
	if (current == NULL) {		//由于不能在空树中插入, 递归终结
		median = new_entry;
		right_branch = NULL;
		result = overflow;
	} 
	else { //查找当前结点
		if (search_node(current, new_entry, position) == success)
			result = duplicate_error;
		else {
			Record extra_entry;
			B_node<Record, order> *extra_branch;
			result = push_down(current->branch[position], new_entry,
			extra_entry, extra_branch);
			if (result == overflow) { 
                if (current->count < order-1) {
                    result = success;
                    push_in(current, extra_entry, extra_branch, position);
				} 
				//记录中间元素, 右分支上到较高层结点
				else split_node(current, extra_entry, extra_branch,
                                position, right_branch, median);
			} 
		} 
	} 
	return result;
}

template <class Record, int order>
void B_tree<Record, order>::push_in(B_node<Record, order> *current,const Record &entry,
								   B_node<Record, order> *right_branch,int position)
{
	//移动后续元素到右边
	for (int i = current->count; i > position; i--) {
		current->data[i] = current->data[i-1];
		current->branch[i+1] = current->branch[i];
	} 
	current->data[position] = entry;
	current->branch[position+1] = right_branch;
	current->count++;
}

template <class Record, int order>
void B_tree<Record, order> ::split_node(B_node<Record, order> *current, 
										const Record &extra_entry,		//待插入元素
										B_node<Record, order> *extra_branch,
										int position, 	//新元素所去结点的序号
										B_node<Record, order> * &right_half, 
										Record &median)	//中间元素
{
	right_half = new B_node<Record, order>;
	int mid = order/2;     	//从中间元素开始将进入右半部分
	if (position <= mid) { 	//情况1：新结点在左半部分
		for (int i = mid; i < order-1; i++) { //移动元素到右半部分
			right_half->data[i-mid] = current->data[i];
			right_half->branch[i+1-mid] = current->branch[i+1];
		} 
		current->count = mid;
		right_half->count = order-1-mid;
		push_in(current, extra_entry, extra_branch, position);
	} 
	else { 		//情况2：新结点在右半部分
		mid++; 	//临时留在左半部分
		for (int i = mid; i < order-1; i++) {	//右移元素
			right_half->data[i-mid] = current->data[i];
			right_half->branch[i+1-mid] = current->branch[i+1];
		} 
		current->count = mid;
		right_half->count = order-1-mid;
		push_in(right_half, extra_entry, extra_branch, position-mid);
	} 
	median = current->data[current->count-1];
	//在左半部分移除中间元素
	right_half->branch[0] = current->branch[current->count];
	current->count--;
}
