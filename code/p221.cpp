template <class T>
SeqList<T>& Graph<T>::BreadthFirstSearch(const T& beginVertex)
{
    int start,nextadj;		//顶点在顶点表中位置
    Queue<T> Q;
    SeqList<T> *L;
    T vertex, nextvertex;
    start = GetVertexPos(beginVertex);
    L = new SeqList<T>;
    Q.QInsert(beginVertex);   //初始化队列
    (*L).Insert(beginVertex); //访问顶点
    while (!Q.QEmpty())  {
        //出队
        vertex = Q.QDelete();
                    
        //取邻接点
        nextadj = GetFirstNeighbor(vertex);
        nextvertex = vertexList.GetVertex(nextadj);
        //若顶点未被访问, 则入队
        while (nextvertex)  {
            if (!FindVertex(*L,nextvertex))  {	//没被访问
                (*L).Insert(nextvertex); 		//记录连通分量中的顶点访问序列
                Q.QInsert(nextvertx);
            }
            nextadj = GetNextNeighbor(start,nextadj+1);
            nextvertex = vertexList.GetVertex(nextadj);
        }
    }
    return *L;
}

