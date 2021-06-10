//已知线性表La和Lb中的元素按值非递减排列, 归并La和Lb得到新的线性表Lc, Lc的元素也按值非递减排列
void MergeList(LinearList La, LinearList Lb, LinearList &Lc) {
    Lc.Create(); 
    i = j = 1;　k = 0;
    La_len = La.Length();
    Lb_len = Lb.Length();
    while ((i <= La_len) && (j <= Lb_len)) {  //La和Lb均非空
        La.Find(i, ai);  Lb.Find(j, bj);
        if (ai <= bj) { Lc.Insert(++k, ai);  ++i; }
        else { Lc.Insert(++k, bj);  ++j; }
    }
    while (i <= La_len) {
        La.Find(i, ai);
        Lc.Insert(++k, ai);
    }
    while (j <= Lb_len) {
        Lb.Find(j, bj);
        Lc.Insert(++k, bj);
    }
} 
