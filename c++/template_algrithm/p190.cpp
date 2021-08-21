void Select(HTNode *HT, int k, int &s1, int &s2)
{
    int i;  s1, s2 = 1;
    T min1, min2 = HT[1].weight;
    for (i = 2; i <= k; i++) {
         if (HT[i].parent == 0 && i != s1 && i != s2)
             if (HT[i].weight<min1) {
                 s2 = s1; min2 = min1;
                 s1 = i; min1 = HT[i].weight; 
             }
             else if(HT[i].weight < min2)  { s2 = i; min2 = HT[i].weight; }
    }
}

//w存放n个字符的权值(均大于0), 构造赫夫曼树HT
template <class T>
void HuffmanTree(HTNode*&HT, T *w, int n)
{
    int c, f, i, m, s1, s2;
    HTNode *p;
    if (n <= 1) return;
    m = 2 * n - 1;
    HT = new HTNode[m+1]; //动态分配数组存储赫夫曼树 0号单元不用
    for(p = HT,i = 1;i <= n; ++i, ++p, ++w)
        p->weight = *w;
    for (i = n+1; i <= m;++i) {  //建赫夫曼树
        Select(HT, i-1, s1, s2);
        //选择parent为0且weight最小的两个结点, 其序号分别为s1和s2
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].left = s1;
        HT[i].right = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}
