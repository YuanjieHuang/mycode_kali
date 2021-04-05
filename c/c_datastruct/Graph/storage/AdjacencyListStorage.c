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
    typedef struct ArcNode{
        int adjvex;//邻接点在数组中的位置下标
        struct ArcNode * nextarc;//指向下一个邻接点的指针
        InfoType * info;//信息域
    }ArcNode;
    typedef struct VNode{
        VertexType data;//顶点的数据域
        ArcNode * firstarc;//指向邻接点的指针
    }VNode,AdjList[MAX_VERTEX_NUM];//存储各链表头结点的数组
    typedef struct {
        AdjList vertices;//图中顶点的数组
        int vexnum,arcnum;//记录图中顶点数和边或弧数
        int kind;//记录图的种类
    }ALGraph;