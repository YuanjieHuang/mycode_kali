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
