template <class T>
void Graph<T>::Components () 
{ 
    int count; 
    visited = new int[numofVertice]; //创建visited 
    for (int i = 0; i < numofVertice; i++)
        visited[i] = 0; //visited 初始化
    for (i = 0; i < numofVertice; i++) 
        if (!visited[i]) {		//检测所有顶点是否访问过
            DFS(i, visited);	//从未访问的顶点出发访问
            count++;
            OutputNewComponent();	//输出一个连通分量
        }
    delete [] visited;			//释放visited
}
