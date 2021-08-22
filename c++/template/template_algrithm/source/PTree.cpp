//合并以第i个元素和第j个元素为树根结点的集合
template<class T>
void Union(PTree<T> *t, int i, int j)
{
    if (t->nodes[i].parent != -1 || t->nodes[j].parent != -1) {
        cerr << 调用参数不正确 << endl;
        return;
    }
    t->nodes[j].parent = i;   //将i置为两个集合共同的根结点
}
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
