 //已知线性表Lb中的元素依值非递减有序排列, 构造线性表La, 使La中只包含Lb中所有值不相同的元素
void purge(LinearList &La, LinearList Lb) {
    La.Create();  //初始化La为空表
    La_len = La.Length();
    Lb_len = Lb.Length(); 	//求线性表的长度
    for (i = 1;  i <= Lb_len;  i++) {
        Lb.Find(i, e);  	//取Lb中第i个元素赋给e
        if (La.IstEmpty() || !equal(en, e))  
           La.Insert(++La_len, e);    //La中不存在和e相同的元素, 则将e插入之
        en = e;
    } 
}
