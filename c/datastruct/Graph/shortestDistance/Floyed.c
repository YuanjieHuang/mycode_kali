/*
    弗洛伊德的核心思想是：对于网中的任意两个顶点（例如顶点 A 到顶点 B）来说，之间的最短路径不外乎有 2 种情况：

        直接从顶点 A 到顶点 B 的弧的权值为顶点 A 到顶点 B 的最短路径；
        从顶点 A 开始，经过若干个顶点，最终达到顶点 B，期间经过的弧的权值和为顶点 A 到顶点 B 的最短路径。

    所以，弗洛伊德算法的核心为：对于从顶点 A 到顶点 B 的最短路径，拿出网中所有的顶点进行如下判断：
    Dis（A，K）+ Dis（K，B）< Dis（A，B）
    其中，K 表示网中所有的顶点；Dis（A，B） 表示顶点 A 到顶点 B 的距离。

*/
    #include <stdio.h>
    #define MAX_VERtEX_NUM 20                   //顶点的最大个数
    #define VRType int                          //表示弧的权值的类型
    #define VertexType int                      //图中顶点的数据类型
    #define INFINITY 65535
    typedef struct {
        VertexType vexs[MAX_VERtEX_NUM];        //存储图中顶点数据
        VRType arcs[MAX_VERtEX_NUM][MAX_VERtEX_NUM];                         //二维数组，记录顶点之间的关系
        int vexnum,arcnum;                      //记录图的顶点数和弧（边）数
    }MGraph;
    typedef int PathMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];     //用于存储最短路径中经过的顶点的下标
    typedef int ShortPathTable[MAX_VERtEX_NUM][MAX_VERtEX_NUM]; //用于存储各个最短路径的权值和
    //根据顶点本身数据，判断出顶点在二维数组中的位置
    int LocateVex(MGraph * G,VertexType v){
        int i=0;
        //遍历一维数组，找到变量v
        for (; i<G->vexnum; i++) {
            if (G->vexs[i]==v) {
                break;
            }
        }
        //如果找不到，输出提示语句，返回-1
        if (i>G->vexnum) {
            printf("no such vertex.\n");
            return -1;
        }
        return i;
    }
    //构造有向网
    void CreateUDG(MGraph *G){
        G->vexnum = 6;
        G->arcnum = 8;
        for (int i=0; i<G->vexnum; i++) {
            G->vexs[i]=i;
        }
        for (int i=0; i<G->vexnum; i++) {
            for (int j=0; j<G->vexnum; j++) {
                G->arcs[i][j]=INFINITY;
            }
        }
        for (int i=0; i<G->arcnum; i++) {
            int v1[]={0,0,0,1,2,3,4,4} ,v2[]={5,4,2,2,3,5,3,5},w[]={100,30,10,5,50,10,20,60};
            int n=LocateVex(G, v1);
            int m=LocateVex(G, v2);
            if (m==-1 ||n==-1) {
                printf("no this vertex\n");
                return;
            }
            G->arcs[n][m]=w;
        }
    }
    //弗洛伊德算法，其中P二维数组存放各对顶点的最短路径经过的顶点，D二维数组存储各个顶点之间的权值
    void ShortestPath_Floyed(MGraph G,PathMatrix *P,ShortPathTable *D){
        //对P数组和D数组进行初始化
        for (int v=0; v<G.vexnum; v++) {
            for (int w=0; w<G.vexnum; w++) {
                (*D)[v][w]=G.arcs[v][w];
                (*P)[v][w]=-1;
            }
        }
        //拿出每个顶点作为遍历条件
        for (int k=0; k<G.vexnum; k++) {
            //对于第k个顶点来说，遍历网中任意两个顶点，判断间接的距离是否更短
            for (int v=0; v<G.vexnum; v++) {
                for (int w=0; w<G.vexnum; w++) {
                    //判断经过顶点k的距离是否更短，如果判断成立，则存储距离更短的路径
                    if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w]) {
                        (*D)[v][w]=(*D)[v][k] + (*D)[k][w];
                        (*P)[v][w]=k;
                    }
                }
            }
        }
    }
    int main(){
        MGraph G;
        CreateUDG(&G);
        PathMatrix P;
        ShortPathTable D;
        ShortestPath_Floyed(G, &P, &D);
        for (int i=0; i<G.vexnum; i++) {
            for (int j=0; j<G.vexnum; j++) {
                printf("%d ",P[i][j]);
            }
            printf("\n");
        }
        for (int i=0; i<G.vexnum; i++) {
            for (int j=0; j<G.vexnum; j++) {
                printf("%d ",D[i][j]);
            }
            printf("\n");
        }
        return 0;
    }