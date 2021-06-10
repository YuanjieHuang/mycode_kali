 //将所有在Lb中但不在La中的元素插入到La中
void union(LinearList &La, LinearList Lb) 
{
    La_len = La.Length();
    Lb_len = Lb.Length();	//求线性表的长度
    for (i = 1;　i <= Lb_len;　i++) {
        Lb.Find(i, e); 	//取Lb中第i个数据元素赋给e
        if(!La.Search(e)) 	//La中不存在和e相同的元素, 则将e插入到La中
        La.Insert(++La_len, e);  
    }
}
