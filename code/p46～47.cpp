void Initialize(int n)  //初始化n个类, 每个类仅有一个元素
{   
    node = new EquivNode[n + 1];
    for (int e = 1; e <= n; e++) {
        node[e].E = e;
        node[e].link = 0;
        node[e].size = 1;
    }
}

void Union(int i, int j)  //合并类i和类j, 使i代表较小的类
{   
    if (node[i].size > node[j].size)
        swap (i, j);
    //改变较小类的E值
    int k;
    for (k = i; node[k].link; k = node[k].link)
        node[k].E = j;
    node[k].E = j; //链尾结点
    //在链表j的首结点之后插入链表i, 并修改新链表的大小
    node[j].size += node[i].size;
    node[k].link = node[j].link;
    node[j].link = i;
}

int Find(int e)
{   //搜索包含元素i的类
    return node[e].E;
}
