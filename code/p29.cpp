//创建一个单向链表, finished是停止建表输入标志, 是所有输入值中不可能出现的数值
template <class Type>
LinkedList <Type> :: LinkedList()
{  
    ListNode<Type> *p;
    first =  NULL;	//创建空表
    Type value;	
    cin >> value;   
    while (value != finished)  {  
        p= new ListNode<Type>(value, first);
        first = p;
        cin >> value;  
    }
}
