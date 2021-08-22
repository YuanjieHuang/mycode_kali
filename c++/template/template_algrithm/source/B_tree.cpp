template <class Record, int order>
Error_code B_tree<Record, order>::recursive_search_tree(B_node<Record, order> 
													   *current, Record &target)
{
	Error_code result = not_present;
	int position;
	if (current != NULL) {
		result = search_node(current, target, position);
		if (result == not_present)
			result = recursive_search_tree(current->branch[position], target);
		else	
			target = current->data[position];
	} 
	return result;
}

template <class Record, int order>
Error_code B_tree<Record, order>::search_node(B_node<Record, order> *current,
											  const Record &target, int &position)
{
	position = 0;
	while (position < current->count && target > current->data[position])
		position++ ; 		//顺序查找
	if (position < current->count && target == current->data[position])
		return success;
	else
		return not_present;
}
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
template <class Record, int order>
Error_code B_tree<Record, order>::remove(const Record &target)
{
	Error_code result;
	result = recursive_remove(root, target);
	if (root != NULL && root->count == 0) { 	//根现为空
		B_node<Record, order> *old_root = root;
		root = root->branch[0];
		delete old_root;
	} 
	return result;
}

template <class Record, int order>
Error_code B_tree<Record, order>::recursive_remove(B_node<Record, order> *current,
												   const Record &target)
{ 
	Error_code result;
	int position;
	if (current == NULL) result = not_present;
	else {	//目标在当前结点
		if (search_node(current, target, position) == success) {
			result = success;
			if (current->branch[position] != NULL) { //不在叶结点
				copy_in_predecessor(current, position);
				recursive_remove(current->branch[position],
				current->data[position]);
			} 
			else remove_data(current, position); 	//从叶结点删除
		}
		else result = recursive_remove(current->branch[position], target);
		if (current->branch[position] != NULL)
			if (current->branch[position]->count < (order-1)/2)	
				restore(current, position);
	} 
	return result;
}

template <class Record, int order>
void B_tree<Record, order> ：：remove_data(B_node<Record, order> *current, int position)
{
	for (int i = position; i < current->count-1; i++)
		current->data[i] = current->data[i+1];
	current->count--;
}

template <class Record, int order>
void B_tree <Record, order>::copy_in_predecessor(B_node<Record, order> *current,
											     int position)
{
	B_node<Record, order> *leaf = current->branch[position];
	//首先进入左分支
	while (leaf->branch[leaf->count] != NULL)
		leaf = leaf->branch[leaf->count];		//到最右下
	current->data[position] = leaf->data[leaf->count-1];
}

template <class Record, int order>
void B_tree<Record, order>::restore(B_node<Record, order> *current, int position)
{
	if (position == current->count) 	//最右分支
		if (current->branch[position-1]->count > (order-1)/2)
			move_right(current, position-1);
		else
			combine(current, position);
	else if (position == 0) 		//最左分支
		if (current->branch[1]->count > (order-1)/2)
			move_left(current, 1);
		else
			combine(current, 1);
	else 			  //中间分支
		if (current->branch[position-1]->count > (order-1)/2)
			move_right(current, position-1);
		else if (current->branch[position+1]->count > (order-1)/2)
			move_left(current, position+1);
		else combine(current, position);
} 

template <class Record, int order>
void B_tree<Record, order>::move_left(B_node<Record, order> *current, int position)
{
	B_node<Record, order>
		*left_branch = current->branch[position-1],
		*right_branch = current->branch[position];
	left_branch->data[left_branch->count] = current->data[position-1]; //从双亲取元素
	left_branch->branch[++left_branch->count] = right_branch->branch[0];
	current->data[position-1] = right_branch->data[0];
	//右元素加入双亲
	right_branch->count--;
	for (int i = 0; i < right_branch->count; i++) {
		right_branch->data[i] = right_branch->data[i+1];
		right_branch->branch[i] = right_branch->branch[i+1];
	}
	right_branch->branch[right_branch->count] =
						   right_branch->branch[right_branch->count+1];
}

template <class Record, int order>
void B_tree<Record, order>::move_right(B_node<Record, order> *current, int position)
{
	B_node<Record, order>
		*right_branch = current->branch[position+1],
		*left_branch = current->branch[position];
	right_branch->branch[right_branch->count+1] =
                         right_branch->branch[right_branch->count];
	for (int i = right_branch->count ; i > 0; i--) {
		//为新元素腾出空间
		right_branch->data[i] = right_branch->data[i-1];
		right_branch->branch[i] = right_branch->branch[i-1];
	} 
	right_branch->count++ ;
	right_branch->data[0] = current->data[position];
	//从双亲取元素
	right_branch->branch[0] = left_branch->branch[left_branch->count--];
	current->data[position] = left_branch->data[left_branch->count];
}

template <class Record, int order>
void B_tree<Record, order>::combine(B_node<Record, order> *current, int position)
{
	int i;
	B_node<Record, order>
		*left_branch = current->branch[position-1],
		*right_branch = current->branch[position];
	left_branch->data[left_branch->count] = current->data[position-1];
	left_branch->branch[++left_branch->count] = right_branch->branch[0];
	for (i = 0; i < right_branch->count; i++) {
		left_branch->data[left_branch->count] = right_branch->data[i];
		left_branch->branch[++left_branch->count] = right_branch->branch[i+1];
	} 
	current->count--;
	for (i = position-1; i < current->count; i++) {
		current->data[i] = current->data[i+1];
		current->branch[i+1] = current->branch[i+2];
	} 
	delete right_branch;
}

