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

//顺序搜索的迭代算法, 0号元素为监视哨
template <class Type>
int SqSTable <Type>::Search(const Type & x) const
{
    Element[0].setKey (x);
    int i = CurrentSize;
    while (Element[i].getKey () != x) i--;
    return i;
}
//二分查找的迭代算法 
template <class Type> 
int  SqSTable <Type>::BinarySearch(const Type & k) const
{	      
    int high = CurrentSize,　low = 1,　mid;		//步骤1:设置初始区间
    while (low <= high) {		       			//步骤2:表空测试
        mid = (low + high) / 2;		  		//步骤3:得到中点
        if (Element[mid].getKey() < k) 
            low = mid + 1;						//调整到右半区
        else if (Element[mid].getKey() > k) 
            high = mid - 1;        				//调整到左半区
        else return mid;   					//查找成功, 返回元素位置
    }	  
    return 0;									//查找失败
}
