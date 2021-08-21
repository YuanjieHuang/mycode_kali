const　int NumVertices = 10; //图中最大顶点个数

//计算从单个顶点到其他各个顶点的最短路径
//Graph是一个具有n个顶点的带权有向图, 各边上的权值由Edge[i][j]给出
//本算法建立一个数组 dist[j](0 <= j < n), 是当前求到的从顶点v到顶点j
//的最短路径长度, 同时用数组path[j](0 <= j < n)存放求到的最短路径 
template <Class VertexType, class EdgeType>
void Graph< VertexType,EdgeType > ::ShortestPath (const　int n, const　int v)
{
	for (int i = 0; i < n; i++) { 
		dist[i] = Edge[v][i]; 	//dist数组初始化
		S[i] = 0;				//红点标记数组, 等于１为红点
		if (i != v && dist[i] < MAXINT) 
			path[i] = v;
		else
			path[i] = -1; 	//path数组初始化 
	}
	S[v] = 1;  				//顶点v加入红点集
	//选择当前不在集合S中具有最短路径的顶点u 
	for (i = 0; i < n-1; i++) {
		int min = MAXINT;
		int u = v;
		for (int j = 0; j < n; j++) 
			if (!S[j] && dist[j] < min) {
				u = j; 
				min = dist[j];
			} 
		S[u] = 1; //将顶点u加入集合S 
		for (int w = 0; w < n; w++) //修改
			if (!S[w] && Edge[u][w] < MAXINT && dist[u] + Edge[u][w] < dist[w]) {
				dist[w] = dist[u] + Edge[u][w];
				path[w] = u; 
			} 
	} 
}
