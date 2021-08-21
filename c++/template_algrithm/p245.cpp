void Graph:: NonPreFirstTopSort ()
{
    int top = -1;            		//入度为0的顶点栈初始化
    for (int i = 0; i < n; i++)    	//入度为0顶点进栈
        if (NodeTable[i].count == 0) { NodeTable[i].count = top;  top = i; }
    for (i = 0; i < n; i++)        	//期望输出n个顶点
        if (top == -1)　{          	//中途栈空,转出
            cout << "网络中有回路(有向环)" << endl;
            return;
        }
    else {                       	//继续拓扑排序
        int j = top;  top = NodeTable[top].count ;     //退栈
        cout << j << endl;       	//输出
        Edge<int> * l = NodeTable[j].adj;
        while (l) {          		//扫描该顶点的出边表
             int k = l -> adjver;	//邻接点
             if (-- NodeTable[k].count == 0)   //该顶点入度减1,减至0就入栈
             { NodeTable[k].count = top;  top = k; }   
             l = l -> nextadj;					
         }
    }
}
