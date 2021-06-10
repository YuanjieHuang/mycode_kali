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
