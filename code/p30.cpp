//创建一个单向链表, finished是停止建表输入标志, 是所有输入值中不可能出现的数值
template <class Type>
LinkedList <Type>::LinkedList() 
{ 
    ListNode<Type> *p, *rear;
    Type value;	
    first = NULL;
    rear = NULL;
    cin >> value;   
    while (value != finished) {
        p= new ListNode<Type>(value, NULL);
        if (first == NULL)  first = p;  	//第一个结点的处理 
        else  rear->link = p;       		//其他结点的处理 
        rear = p;        					//r指向新的尾结点
        cin >> value;   
    }
    if (rear !＝ NULL)  rear->link = NULL; //对非空表, 最后结点的指针域放空指针 
}
