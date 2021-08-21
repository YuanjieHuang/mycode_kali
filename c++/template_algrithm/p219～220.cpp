template <class T>
SeqList<T>& Graph<T>::DFSSearch()
{   
    int *visited=new int[numofVertice], count = 0;
    for (int i = 0; i < numofVertice; i++) visited[i] = 0;
    SeqList<T> *L;
    for (int i = 0;i < numofVertice; i++)  
        if  (!visited[i]) L[++count] = DFS(i, visited);
    delete [] visited;
    L.Length = count;		//count为连通分量的个数
    return L;
}

template <class T>
SeqList<T>& Graph<T>::DFS(const int v, int *visited)
{   
    SeqList<T> *L;
    T vertex = vertexList.GetVertex(v);
    L = new  SeqList<T>;
    visited[v] = 1;
    (*L).Insert(vertex);  //记录连通分量中的顶点访问序列
    int w = GetFirstNeihbor(v)
    while (w != -1)  {
        if (!visited[w])  DFS(w, visited);
        w = GetNextNeihbor(v, w);
    }
    return *L;
}
