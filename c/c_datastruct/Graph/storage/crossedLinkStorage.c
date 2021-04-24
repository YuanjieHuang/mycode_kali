/*
十字链表法仅适用于存储有向图和有向网。不仅如此，十字链表法还改善了邻接表计算图中顶点入度的问题。
十字链表存储有向图（网）的方式与邻接表有一些相同，都以图（网）中各顶点为首元节点建立多条链表，同时为了便于管理，还将所有链表的首元节点存储到同一数组（或链表）中。
十字链表实质上就是为每个顶点建立两个链表，分别存储以该顶点为弧头的所有顶点和以该顶点为弧尾的所有顶点。
*/
    #define  MAX_VERTEX_NUM 20
    #define  InfoType int//图中弧包含信息的数据类型
    #define  VertexType int
    typedef struct ArcBox{
        int tailvex,headvex;//弧尾、弧头对应顶点在数组中的位置下标
        struct ArcBox *hlik,*tlink;//分别指向弧头相同和弧尾相同的下一个弧
        InfoType *info;//存储弧相关信息的指针
    }ArcBox;
    typedef struct VexNode{
        VertexType data;//顶点的数据域
        ArcBox *firstin,*firstout;//指向以该顶点为弧头和弧尾的链表首个结点
    }VexNode;
    typedef struct {
        VexNode xlist[MAX_VERTEX_NUM];//存储顶点的一维数组
        int vexnum,arcnum;//记录图的顶点数和弧数
    }OLGraph;
    int LocateVex(OLGraph * G,VertexType v){
        int i=0;
        //遍历一维数组，找到变量v
        for (; i<G->vexnum; i++) {
            if (G->xlist[i].data==v) {
                break;
            }
        }
        //如果找不到，输出提示语句，返回 -1
        if (i>G->vexnum) {
            printf("no such vertex.\n");
            return -1;
        }
        return i;
    }
    //构建十字链表函数
    void CreateDG(OLGraph *G){
        //输入有向图的顶点数和弧数
        scanf("%d,%d",&(G->vexnum),&(G->arcnum));
        //使用一维数组存储顶点数据，初始化指针域为NULL
        for (int i=0; i<G->vexnum; i++) {
            scanf("%d",&(G->xlist[i].data));
            G->xlist[i].firstin=NULL;
            G->xlist[i].firstout=NULL;
        }
        //构建十字链表
        for (int k=0;k<G->arcnum; k++) {
            int v1,v2;
            scanf("%d,%d",&v1,&v2);
            //确定v1、v2在数组中的位置下标
            int i=LocateVex(G, v1);
            int j=LocateVex(G, v2);
            //建立弧的结点
            ArcBox * p=(ArcBox*)malloc(sizeof(ArcBox));
            p->tailvex=i;
            p->headvex=j;
            //采用头插法插入新的p结点
            p->hlik=G->xlist[j].firstin;
            p->tlink=G->xlist[i].firstout;
            G->xlist[j].firstin=G->xlist[i].firstout=p;
        }
    }