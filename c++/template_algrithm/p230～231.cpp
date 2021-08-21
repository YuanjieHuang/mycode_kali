int Find(int father[],int e);

template <class T>
void OrderEdge(Graph<T> G, EdgeInfo<T> edge[])
{    
int i,j,n = G.NumberOfVertices;
int k = 0;
for (i = 0; i < n; i++)
        for (j = 0; I < n; i++)
            if (G.getWeight(i,j)) {  
     edge[k].beginVex=i;
                edge[k].endVex=j;
                edge[k].cost= G.getWeight(i,j);
                k++;
            }
// 按权值排序
int temp;
for (i =0; i < k; i++)
             for (j = k-1; j >= i; j--)
  if (edge[j+1].cost < edge[j].cost) { 
  temp = edge[j].cost;
                     edge[j].cost = edge[j+1].cost;
                     edge[j+1].cost = temp;
                 }
}

// 求最小生成树
template <class T>
void MiniSpanTreeKruskal(Graph<T> G, EdgeInfo<T> edge[])
{ 
    int Father[k];
    int vf1, vf2;
    for (i = 0; i < k; i ++) Father[i] = 0;
    for (i = 0; i < k; i ++)
    {
        vf1 = Find(Father,edge[i].beginVex);
        vf2 = Find(Father,edge[i].endVex);
        if (vf1 != vf2)
        {   Father[vf2] = vf1;
            cout << Edges[i].beginVex << Edges[i].endVex;  // 输出一条生成树的边
        }
    }
}

// 寻找顶点v所在树的根结点 
int Find(int Father[],int v)
{
    int t;
    t = v;
    while (Father[t] > 0)
        t = Father[t];
    return(t);
}
