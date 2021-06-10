//公有函数：从顶点x开始深度优先搜索
template <class T> 
void Graph<T>::DfnLow(const int x)
{ 
    int count = 1;				//num是访问计数器 
    dfn = new int[numofVertice];	//dfn是深度优先数
    low = new int[numofVertice];	//low是最小祖先访问顺序号 
    for (int i = 0; i < numofVertice; i++) { 
        dfn[i] = low[i] = 0;		//给予访问计数器num及dfn[u]和low[u]初值
    } 
    DfnLow(x, -1); 				//从根x开始
    delete[] dfn; 
    delete[] low; 
} 

//私有函数：从u开始深度优先搜索计算dfn和low, 在产生的生成树中v是u的双亲
template <class T>
void Graph<T>::DfnLow(const int u, const int v)
{ 
    dfn[u] = low[u] = count++;
    int w = GetFirstNeighbor (u);
    while (w != -1) { 			//对u所有邻接顶点w循环 
        if (dfn[w] == 0) {			//未访问过, w是u的孩子
            DfnLow (w, u);			//从w递归深度优先搜索 
            low[u] = min2 (low[u], low[w]);	//子女w的low[w]先求出, 再求low[u] 
        }
        else if (w != v) 					//w访问过且w不是v,是回边 
            low[u] = min2 (low[u], dfn[w]);	//根据回边另一顶点w调整low[u]
        w = GetNextNeighbor (u, w); 		//找顶点u在w后面的下一个邻接顶点 
    }
}
