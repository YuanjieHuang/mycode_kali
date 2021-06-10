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
