class Graph{                     
    friend class <int>Vertex;
    friend class <int, int>Edge;
private:
    Vertex<int, int> *NodeTable;	//数据域和入度域均设为整型		
    int n;					
public:
    Graph(const int vertices = 0):n(vertices) {
        NodeTable = new vertex<int, int>[n];	
    };
    void TopologicalOrder();
}  
