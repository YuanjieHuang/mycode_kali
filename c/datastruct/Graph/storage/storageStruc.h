/*
图更多的是采用链表存储，具体的存储方法有 3 种，分别是邻接表、邻接多重表和十字链表。
邻接表既适用于存储无向图，也适用于存储有向图。
在图中，如果两个点相互连通，即通过其中一个顶点，可直接找到另一个顶点，则称它们互为邻接点。
邻接指的是图中顶点之间有边或者弧的存在。
邻接表存储图的实现方式是，给图中的各个顶点独自建立一个链表，用节点存储该顶点，用链表中其他节点存储各自的邻接点。
*/
#define  MAX_VERTEX_NUM 20//最大顶点个数
#define  VertexType int//顶点数据的类型
#define  InfoType int//图中弧或者边包含的信息的类型
typedef struct ArcNode
{
    int adjvex;//邻接点在数组中的位置下标
    struct ArcNode * nextarc;//指向下一个邻接点的指针
    InfoType * info;//信息域
}ArcNode;

typedef struct VNode
{
    VertexType data;//顶点的数据域
    ArcNode * firstarc;//指向邻接点的指针
}VNode, AdjList[MAX_VERTEX_NUM];//存储各链表头结点的数组

typedef struct 
{
    AdjList vertices;//图中顶点的数组
    int vexnum,arcnum;//记录图中顶点数和边或弧数
    int kind;//记录图的种类
}ALGraph;


/*
邻接多重表仅适用于存储无向图或无向网。
邻接多重表存储无向图的方式，可看作是邻接表和十字链表的结合。
同邻接表和十字链表存储图的方法相同，都是独自为图中各顶点建立一张链表，存储各顶点的节点作为各链表的首元节点，
同时为了便于管理将各个首元节点存储到一个数组中。
*/
#define MAX_VERTEX_NUM 20                   //图中顶点的最大个数
#define InfoType int                        //边含有的信息域的数据类型
#define VertexType int                      //图顶点的数据类型
typedef enum {unvisited,visited}VisitIf;    //边标志域
typedef struct EBox
{
    VisitIf mark;                           //标志域
    int ivex,jvex;                          //边两边顶点在数组中的位置下标
    struct EBox * ilink,*jlink;             //分别指向与ivex、jvex相关的下一个边
    InfoType *info;                         //边包含的其它的信息域的指针
}EBox;
typedef struct VexBox
{
    VertexType data;                        //顶点数据域
    EBox * firstedge;                       //顶点相关的第一条边的指针域
}VexBox;
typedef struct 
{
    VexBox adjmulist[MAX_VERTEX_NUM];//存储图中顶点的数组
    int vexnum,degenum;//记录途中顶点个数和边个数的变量
}AMLGraph;

/*
十字链表法仅适用于存储有向图和有向网。不仅如此，十字链表法还改善了邻接表计算图中顶点入度的问题。
十字链表存储有向图（网）的方式与邻接表有一些相同，都以图（网）中各顶点为首元节点建立多条链表，同时为了便于管理，还将所有链表的首元节点存储到同一数组（或链表）中。
十字链表实质上就是为每个顶点建立两个链表，分别存储以该顶点为弧头的所有顶点和以该顶点为弧尾的所有顶点。
*/
#define  MAX_VERTEX_NUM 20
#define  InfoType int//图中弧包含信息的数据类型
#define  VertexType int
typedef struct ArcBox
{
    int tailvex,headvex;//弧尾、弧头对应顶点在数组中的位置下标
    struct ArcBox *hlik,*tlink;//分别指向弧头相同和弧尾相同的下一个弧
    InfoType *info;//存储弧相关信息的指针
}ArcBox;

typedef struct VexNode
{
    VertexType data;//顶点的数据域
    ArcBox *firstin,*firstout;//指向以该顶点为弧头和弧尾的链表首个结点
}VexNode;

typedef struct 
{
    VexNode xlist[MAX_VERTEX_NUM];//存储顶点的一维数组
    int vexnum,arcnum;//记录图的顶点数和弧数
}OLGraph;

int LocateVex(OLGraph * G,VertexType v)
{
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
void CreateDG(OLGraph *G)
{
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