//在带权有向图中有的边具有负的权值, 从顶点v找到所有其他顶点的最短路径
void Graph::BellmanFord (const　int n, const　int v ) 
{ 
    for (int i = 0; i < n; i++) {
        dist[i] = Edge[v][i]; 
        if (i != v && dist[i] < MAXINT) path[i] = v; 
        else path[i] = -1;
    }
    for (int k = 2; k < n; k++) 
        for (int u = 0; u < n; u++) 
            if  (u != v) 
                for(i = 0; i < n; i++)
                    if (Edge[i][u] > 0 && Edge[i][u] < MAXINT && 
                        dist[u] > dist[i] + Edge[i][u]) {
                        dist[u] = dist[i] + Edge[i][u]; 
                        path[u] = i;
                    } 
} 
