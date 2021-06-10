template<class Type> void LinkedList<Type> :: Inverse () 
{
	ListNode<Type> *p, *head = new ListNode<Type> ();
	while (first != NULL) {
		p = first;  first = first->link;		//摘下first链头结点
		p->link = head->link;  head->link = p;	//插入head链前端
	}
	first = head->link; delete head;			//重置first
}

