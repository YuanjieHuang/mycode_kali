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

