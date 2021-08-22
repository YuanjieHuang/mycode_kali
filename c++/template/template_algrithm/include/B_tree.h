template <class Record, int order>
struct B_node {
	//数据成员;
	int count;
	Record data[order-1];
	B_node<Record, order> *branch[order];
	//构造函数;
	B_node() {count=0;}; 
};

enum  Error_code{not_present, duplicate_error, overflow, success};

template <class Record, int order>
class B_tree {
public：
	Error_code search_tree(Record &target);
	Error_code insert(const Record &new_entry);
	B_tree() { root=NULL; };	
	Error_code remove(const Record &target);
private：
	B_node<Record, order> *root;
	Error_code recursive_search_tree(B_node<Record, order> *current, Record &target);
	Error_code search_node(B_node<Record, order> *current, const Record &target, int
							&position);
	Error_code push_down(B_node<Record, order> *current, const Record &new_entry,
						   Record &median, B_node<Record, order> * &right_branch);
	void push_in(B_node<Record, order> *current,const Record &entry,
                 B_node<Record, order> *right_branch, int position);
	void split_node(B_node<Record, order> *current, 		//待分裂结点
                    const Record &extra_entry,B_node<Record, order> *extra_branch,
                    int position, 						//extra entry 所取的结点
	                B_node<Record, order>* &right, Record &median);//右半部分新结点
	
	Error_code recursive_remove(B_node<Record, order> *current, const Record 
								 &target);
	void remove_data(B_node<Record, order> *current, int position);
	void copy_in_predecessor(B_node<Record, order> *current, int position);
	void restore(B_node<Record, order> *current, int position);
	void move_left(B_node<Record, order> *current, int position);
	void move_right(B_node<Record, order> *current, int position);
	void combine(B_node<Record, order> *current, int position);
};
