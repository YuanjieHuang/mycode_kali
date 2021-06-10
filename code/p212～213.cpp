const int DefaultSize = 10; 
template <class T> class Graph; 
template <class T>
struct Edge { 
    int adjvex; 
    T cost; 	//边的权
    Edge<T> *nextadj; 
    Edge() {} 
    Edge(int D, T C) : adjvex (D), cost (C), nextadj (NULL) {} 
    int operator != (const Edge &E)const { return adjvex != E.adjvex; } 
}

template <class VertexType, class T> 
struct Vertex { 
    VertexType vertex; 
    Edge<T> *firstadj;
}

template <class VertexType, class T>
class Graph { 
    friend class vertex <VertexType, T>;
    friend class Edge<T>; 
private:
    Vertex<VertexType, T> *NodeTable;
    int NumVertices;
    int MaxVertices;
    int NumEdges; 
    int GetVertexPos(const VertexType & vertex);
public:
    Graph(int sz); 
    ~Graph();

    VertexType GetVertex(const int i) { 
        return i >= 0 && i < NumVertices ? NodeTable[i].vertex : NULL; 
    } 
    int NumberOfVertices() { return NumVertices; } 
    int NumberOfEdges() { return NumEdges; }
    void InsertVertex(const VertexType & vertex);
    void RemoveVertex(const int v); 
    void InsertEdge(const int v1, const int v2, const T weight); 
    void RemoveEdge(const int v1, const int v2);
    T GetWeight(const int v1, const int v2);
    SeqList<VertexType> GetVertex(int v);
    int GetFirstNeighbor(const int v); 
    int GetNextNeighbor(const int v1, const int v2);
    //实用方法
    SeqList< VertexType >& BreadthFirstSearch(const VertexType & beginVertex); 
    void DFSSearch();
    void DFS(const int v, int visited[]);  
    void Components();		//求连通分量
    void DfnLow(const int v);	//求关结点
    void DfnLow(const int u, const int v);

}
