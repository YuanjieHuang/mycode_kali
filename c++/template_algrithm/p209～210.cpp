const int MaxGraphSize = 30;

template <class T> 
class Graph  {
private:
    SeqList<T> vertexList;
    int edge[MaxGraphSize][MaxGraphSize];
    int numofVertices, numofArcs;
    int FindVertex(SeqList<T> &L, const T& vertex);
    int GetVertexPos(const T& vertex);
public: 
    Graph(void);   
    //数据访问方法
    int NumberOfVertices(void) const;
    int GetWeight(const T& vertex1, const T& vertex2);
    SeqList<T> GetVertex(int v);
    SeqList<T>& GetNeighbors(const T& vertex);
     
    //图的更新方法
    void InsertVertex(const T& vertex);
    void InsertEdge(const T& vertex1, const T& vertex2,int weight);
    void DeleteVertex(const T& vertex);
    void DeleteEdge(const T& vertex1, const T& vertex2);    

    SeqList<T>& BreadthFirstSearch(const T& beginVertex);   
    void DFS();
    void DFS(const int v, int visited[]);  
    void Components();		//求连通分量
    void DfnLow(const int v);	//求关结点
    void DfnLow(const int u, const int v);
};
