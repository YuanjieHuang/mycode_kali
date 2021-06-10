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
