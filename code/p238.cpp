void Graph::ShortestPath(const n , const int v)
{ 
    int u, k;
    int scratch[n];
    Edge *p;
    Queue<int> Q;						//声明一个队列
    for (i = 0; i < n; i++)  {			//初始化
         path[i] = -1;
         dist[i] = -1;
         scratch[i] = 0;
    }
    dist[v] = 0;							//初始顶点v的dist值为0
    Q.QInsert(v);						//初始顶点v入队
    scratch[v]++;						//scratch[v]值变为1
    while(! Q.QEmpty())  {
        u = Q.QDelete() ;					//删除队头顶点u
        scratch[u]++;						//scratch[u]值加1
        p = head[u].firstadj;				//p为u的边链的头指针
        //将u的所有邻接顶点入队, 相应修改其path[], dist[]和scratch[]值
        while(p != NULL)  {
            k = p-> adjVer ;				 	//k为u的邻接顶点
            if(dist[u] + p->cost < dist[k])  {	//v途径u到k的路径是否比原来的v到k的路径小
                //若k不在队列中, k入队, scratch[k]的值加1
                if((scratch[k]++) / 2 == 0) Q.QInsert(k) ;
                //若k已在队列中, scratch[k]的值加2
                else scratch[k]++ ;
                //若scratch[k]大于2n, 报告回路存在, 终止程序
                if(scratch[k] > 2 * n)  {
                    cout<<" There is a circle in Graph !"<<endl ;
                    return ;
                 }
                 dist[k] = dist[u] + p->cost ; 
                 path[k] = u ; 
            }
            p = p->nextadj ;
        }
    }
}
