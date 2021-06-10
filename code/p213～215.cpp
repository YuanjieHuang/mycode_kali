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