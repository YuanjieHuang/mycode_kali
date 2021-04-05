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
    typedef struct EBox{
        VisitIf mark;                           //标志域
        int ivex,jvex;                          //边两边顶点在数组中的位置下标
        struct EBox * ilink,*jlink;             //分别指向与ivex、jvex相关的下一个边
        InfoType *info;                         //边包含的其它的信息域的指针
    }EBox;
    typedef struct VexBox{
        VertexType data;                        //顶点数据域
        EBox * firstedge;                       //顶点相关的第一条边的指针域
    }VexBox;
    typedef struct {
        VexBox adjmulist[MAX_VERTEX_NUM];//存储图中顶点的数组
        int vexnum,degenum;//记录途中顶点个数和边个数的变量
    }AMLGraph;