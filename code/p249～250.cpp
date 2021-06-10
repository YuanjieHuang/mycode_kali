//在此算法中需要对邻接表中单向链表的结点加以修改,
//在各结点中增加一个int域cost, 记录该结点所表示的边上的权值
void graph::CriticalPath ()
{
    int i, j;  int p, k;  float e, l;
    float * Ve = new float[n];
    float * Vl = new float[n];
    for (i = 1; i < n+1; i++) Ve[i] = 0;
    for (i = 1;; i < n+1; i++) {
        Edge<float> *p = NodeTable[i].adj;
        while (p != NULL) {					
            k = p->adjver;
            if (Ve[i] + p->cost > Ve[k])
                Ve[k] = Ve[i] + p->cost; 
            p = p->nextadj;
        }
    }
    for (i = 1; i < n+1; i++) Vl[i] = Ve[n-1];
    for (i = n-1; i>0; i--) {	
        p = NodeTable[i].adj;
        while (p != NULL) {
            k = p->adjver;
            if (Vl[k] - p->cost < Vl[i])
                Vl[i] = Vl[k] - p->cost;
            p = p->nextadj;        
        }
    }
    for (i = 0; i < n; i++) {				
         p = NodeTable[i].adj;			
         while (p != NULL) {
             k = p->adjver;					
             e = Ve[i];  l = Vl[k] - p->cost;
             if (l == e)
                 cout << "<" << i << "," << k << “>” << “是关键活动” << endl;
             p = p->nextadj;						
         }
    }
}
