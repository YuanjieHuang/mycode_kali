//构造函数初始化邻接矩阵
template <class T>
Graph<T>::Graph(void)
{
    for (int i = 0; i < MaxGraphSize; i++)
        for (int j = 0; j < MaxGraphSize; j++)
            edge[i][j] = 0;
    numofVertices = numofArcs = 0;
}

template <class T>
int Graph<T>::NumberOfVertices(void) const
{
    return numofVertices;
}

template <class T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2)
{
    int pos1 = GetVertexPos(vertex1), pos2 = GetVertexPos(vertex2);
   
    if (pos1 == -1 || pos2 == -1)  {
        cerr << "GetWeight: a vertex is not in the graph." << endl;
        return -1;
    }

    return edge[pos1][pos2];
}

template <class T>
int Graph<T>::GetFirstNeighbor(const int v)
{
    if (v < 0 || v > numofVertices)
    { cerr << "The vertex is not in the graph." << endl; return -1; }
    for (int i = 0; i < numofVertices; i++)
        if (edge[v][i] > 0 && edge[v][i]<maxint) return i;
    return -1;
}

template <class T>
int Graph<T>::GetNextNeighbor(const int v, const int v1)
{   if (v < 0 || v > numofVertices || v1 <0 || v1 > numofVertices)
    { cerr << "The vertex is not in the graph." << endl; return -1; }
    for (int i = v1+1; i < numofVertices; i++)
        if (edge[v][i] > 0 && edge[v][i] < maxint) return i;
    return -1;
}

template <class T>
void Graph<T>::InsertVertex(const T& vertex)
{
    if (numofVertices+1 > MaxGraphSize)  {  
        cerr << "Graph is full" << endl;
        exit (1);      
    }
    vertexList.Insert(vertex);
    numofVertices++;
}

template <class T>
void Graph<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight)
{
    int pos1 = GetVertexPos(vertex1), pos2 = GetVertexPos(vertex2);
   
    if (pos1 == -1 || pos2 == -1)  {
        cerr << "InsertEdge: a vertex is not in the graph." << endl;
        return;
    }
   
    edge[pos1][pos2] = weight;
}

template <class T>
void Graph<T>::DeleteVertex(const T& vertex)
{
    int pos = GetVertexPos(vertex);  //得到顶点在表中的位置
    int row, col;
   
    if (pos == -1)  {    //若顶点不存在，结束
        cerr << "DeleteVertex: a vertex is not in the graph." << endl;
        return;
    }

    //删除顶点, 修改numofVertices
    vertexList.Delete(vertex);
    numofVertices--;

    //邻接矩阵划分为3个区
    for (row = 0; row < pos; row++)              		//区I
        for (col = pos + 1;col < numofVertices; col++)
            edge[row][col-1] = edge[row][col];

    for (row = pos+1; row < numofVertices; row++)      	//区II
        for (col = pos + 1; col < numofVertices; col++)
            edge[row-1][col-1] = edge[row][col];

    for (row = pos+1; row < numofVertices; row++)      	//区III
        for (col = 0; col < pos; col++)
            edge[row-1][col] = edge[row][col];
}

template <class T>
void Graph<T>::DeleteEdge(const T& vertex1, const T& vertex2)
{
    int pos1 = GetVertexPos(vertex1), pos2 = GetVertexPos(vertex2);

    if (pos1 == -1 || pos2 == -1)  {
        cerr << "DeleteEdge: a vertex is not in the graph." << endl;
        return;
    }
    edge[pos1][pos2] = 0;
}
template <class T>
void Graph<T>::Components () 
{ 
    int count; 
    visited = new int[numofVertice]; //创建visited 
    for (int i = 0; i < numofVertice; i++)
        visited[i] = 0; //visited 初始化
    for (i = 0; i < numofVertice; i++) 
        if (!visited[i]) {		//检测所有顶点是否访问过
            DFS(i, visited);	//从未访问的顶点出发访问
            count++;
            OutputNewComponent();	//输出一个连通分量
        }
    delete [] visited;			//释放visited
}
template <class T>
void Prim(Graph &G, T  closeVertex[])
{
	int n = G.NumOfVertices(), minCost;
	int *lowCost = new int[n];
	int i, j, k;
	//从序号为0的顶点出发构造最小生成树
	for (i = 0; i < n; i ++)  {	//初始化
		lowCost[i] = G.GetWeight(0, i);
		closeVertex[i] = G.GetVertex(0);
	}
	lowCost[0] = -1;

	//寻找当前最小权值的边的顶点 
	for (i = 1; i < n; i++) 	{
		minCost = MaxWeight;		//MaxWeight为图类中定义的最大权值 
		for (j = 1; j < n; j++)	{
			if(lowCost[j] > 0&&lowCost[j] < minCost)  {
				minCost = lowCost[j];
				k = j;
			}
		}

		lowCost[k] = -1;
		for (int j = 1; j < n; j++)  { 	//修改其他顶点的边的权值
			if (G.GetWeight(k, j) < lowCost[j])  {
				lowCost[j] = G.GetWeight(k, j); 
				closeVertex[j] = G.GetVertex(k);
			}
		}
	}
}
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
//在带权有向图中有的边具有负的权值, 从顶点v找到所有其他顶点的最短路径
void Graph::BellmanFord (const　int n, const　int v ) 
{ 
    for (int i = 0; i < n; i++) {
        dist[i] = Edge[v][i]; 
        if (i != v && dist[i] < MAXINT) path[i] = v; 
        else path[i] = -1;
    }
    for (int k = 2; k < n; k++) 
        for (int u = 0; u < n; u++) 
            if  (u != v) 
                for(i = 0; i < n; i++)
                    if (Edge[i][u] > 0 && Edge[i][u] < MAXINT && 
                        dist[u] > dist[i] + Edge[i][u]) {
                        dist[u] = dist[i] + Edge[i][u]; 
                        path[u] = i;
                    } 
} 
