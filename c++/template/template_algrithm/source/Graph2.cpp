//构造函数
template <class VertexType, class EdgeType> 
Graph<VertexType, EdgeType>::Graph (const int sz = DefaultSize) :
NumVertices (0), MaxVertices (sz), NumEdges (0)
{ 
    int n, e, k, j; VertexType name, tail, head; 
    EdgeType weight;
    NodeTable = new Vertex<VertexType>[MaxVertices]; //创建顶点表
    cin >> n; //输入顶点个数
    for (int i = 0; i < n; i++)  { //输入各顶点信息
         cin >> name;
         InserVertex (name);
    }
    cin >> e; 						//输入边条数
    for (i = 0; i < e; i++) {		//逐条边输入
        cin >> tail >> head >> weight;
        k = GetVertexPos(tail);
        j = GetVertexPos(head);
        InsertEdge(k, j, weight);
    } 
}

//析构函数
template <class VertexType, class EdgeType>
Graph<VertexType, EdgeType>::~Graph () 
{
    for (int i = 0; i < NumVertices; i++) {
        Edge<EdgeType> *p = NodeTable[i].firstadj;
        while (p != NULL) {		//逐条边释放
            NodeTable[i].firstadj = p -> nextadj; delete p; 
            p = NodeTable[i].firstadj; 
        }
    }
    delete [] NodeTable;			//释放顶点表
}

//根据顶点名vertex查找该顶点在邻接表中的位置
template <class VertexType, class EdgeType>
int Graph<VertexType, EdgeType>::GetVertexPos(const VertexType & vertex)
{
    for (int i = 0; i < NumVertices; i++)
        if (NodeTable[i].data == vertex) return i;
    return -1;
}

//查找顶点v的第一个邻接顶点在邻接表中的位置 
template <Class VertexType, class EdgeType>
int Graph<VertexType, EdgeType>::GetFirstNeighbor(const int v)
{
    if (v != -1) {		//若顶点存在
        Edge<EdgeType> *p = NodeTable[v].firstadj;
        if (p != NULL) return p→adjvex; 
    } 
    return -1;				//若顶点不存在
}

//查找顶点v1在邻接顶点v2后下一个邻接顶点
template <Class VertexType, class EdgeTypeType>
int Graph<VertexType, EdgeType>::GetNextNeighbor(const int v1, const int v2)
{
    if (v1 != -1) {
        Edge<EdgeType> *p = NodeTable[v1].firstadj; 
        while (p != NULL) {
            if (p->adjvex == v2 && p->nextadj != NULL)
                return p->nextadj->adjvex; 	//返回下一个邻接顶点在邻接表中的位置
            else 
                p = p->nextadj;
        }
    }
    return -1; //没有查到下一个邻接顶点返回-1
}

//取两端点为v1和v2的边上的权值
template <Class VertexType, class EdgeType>
EdgeType Graph<VertexType, EdgeType>::GetWeight(const int v1, const int v2)
{
    if (v1 != -1 && v2 != -1) {
        Edge<EdgeType> *p = NodeTable[v1].firstadj;　
        while (p != NULL) {
            if (p->adjvex == v2) 
                return p->cost;
            else 
                p = p->nextadj;
        }
    }
    return 0;
}

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
void Graph::ShortestPath(const n , const int v)
{ 
    int u, k;
    int scratch[n];
    Edge *p;
    Queue<int> Q;						//声明一个队列
    for (i = 0; i < n; i++)  {			//初始化
         path[i] = -1;
         dist[i] = -1;
         scratch[i] = 0;
    }
    dist[v] = 0;							//初始顶点v的dist值为0
    Q.QInsert(v);						//初始顶点v入队
    scratch[v]++;						//scratch[v]值变为1
    while(! Q.QEmpty())  {
        u = Q.QDelete() ;					//删除队头顶点u
        scratch[u]++;						//scratch[u]值加1
        p = head[u].firstadj;				//p为u的边链的头指针
        //将u的所有邻接顶点入队, 相应修改其path[], dist[]和scratch[]值
        while(p != NULL)  {
            k = p-> adjVer ;				 	//k为u的邻接顶点
            if(dist[u] + p->cost < dist[k])  {	//v途径u到k的路径是否比原来的v到k的路径小
                //若k不在队列中, k入队, scratch[k]的值加1
                if((scratch[k]++) / 2 == 0) Q.QInsert(k) ;
                //若k已在队列中, scratch[k]的值加2
                else scratch[k]++ ;
                //若scratch[k]大于2n, 报告回路存在, 终止程序
                if(scratch[k] > 2 * n)  {
                    cout<<" There is a circle in Graph !"<<endl ;
                    return ;
                 }
                 dist[k] = dist[u] + p->cost ; 
                 path[k] = u ; 
            }
            p = p->nextadj ;
        }
    }
}
