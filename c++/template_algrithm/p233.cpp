//在有n个顶点的图中,求从顶点v到其他各顶点的最短路径。 
template <Class VertexType, class EdgeType>
void Graph<VertexType,EdgeType>::ShortestPath(const n, const int v)
{
	int u, k;
	EdgeType *p;
	Queue<int> Q;						//声明一个队列
	for (i = 0; i < n; i ++)  {		//数组path和dist初始化
		path[i] = -1 ;	dist[i] = -1 ;
	}
	dist[v] = 0;						//初始顶点v的dist值为0
	Q.QInsert(v) ;					//初始顶点v入队
	while (!Q.QEmpty())  {
		u = Q.QDelete();				//删除队头顶点u
		p = head[u].firstadj;			//p为u的边链表的头指针
		//将u的未访问的邻接顶点入队,并修改其path[]值和dist[]值
		while (p != NULL)  {
			k = p-> adjVer;
			if (dist[k] == -1)  {
				Q.QInsert(k);
				dist[k] = dist[u] + 1;
				path[k] = u; 
			}
			p = p->nextadj;
		}
	}
}
