//在数组中查找值为x的元素所属的集合
//若找到, 返回树根结点在数组中的序号, 否则, 返回-1
//常量MAXNODE为数组a的最大容量
template<class T>
int Find(PTree<T> *t, T  x) {   
    int i,j;
    i = 0;
    while (i < MAXNODE && t->nodes[i].data != x) i++;
    if (i >= MAXNODE) return –1;    //值为x的元素不属于该组集合, 返回-1
    j = i;
    while (t->nodes[j].parent != -1)  
        j = a[j].parent;
    return j;       //j为该集合的树根结点在数组中的序号
}
