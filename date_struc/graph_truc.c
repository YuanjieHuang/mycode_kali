/*
图结构：包含两部分(顶点Vertex,边Edge)
操作：
1 创建图
2 清空图
3 显示图
4 遍历图
*/
#include <stdio.h>
#include <string.h>
#define MaxNum 20//图最大顶点数
#define MaxValue 65535

typedef struct
{
    char Vertex[MaxNum];                //保存顶点信息
    int Gtype;                          //图的类型，0：无向图，1：有向图
    int VertexNum;                      //顶点的数量
    int EdgeNum;                        //边的数量
    int EdgeWeight[MaxNum][MaxNum];     //保存边的权
    int isTrav[MaxNum];                  //遍历标志
}GraphMatrix;

void createGraph(GraphMatrix *GM)
{
    int i, j, k;
    int weight;                 //权
    char EstartU, EendU;        //边的起止顶点
    printf("input graph's vertex message.\n");
    for(i = 0; i< GM->VertexNum; i++)
    {
        getc(stdin);
        printf("The %dth vertex:", i + 1);
        scanf("%c", &(GM->Vertex[i]));

    }
    printf("Input the right value and vertex of Edge.\n");
    for(k = 0; k < GM->EdgeNum; k++)
    {
        getc(stdin);
        printf("The %d th edge: ", k+1);
        printf("\033[36mRule startVertext endVertex weight\033[0m\n");
        scanf("%c %c %d",&EstartU, &EendU, &weight);
        for(i = 0; EstartU != GM->Vertex[i]; i++ );
        for(j = 0;EendU != GM->Vertex[j]; j++);
        GM->EdgeWeight[i][j] = weight;
        if(GM->Gtype == 0)
        {
            GM->EdgeWeight[j][i] = weight;
        }
    }
}

void clearEdgeWeight(GraphMatrix *GM)
{
    int i, j;
    printf(" clear edge weight.\033[35mVertexNum:%d\033[0m\n", GM->VertexNum);
    for(i = 0; i < GM->VertexNum; i++)
    {
        for(j = 0; j < GM->VertexNum; j++)
        {
            GM->EdgeWeight[i][j] = MaxValue;
            printf("\033[33mE([%d],[%d]) = %d\033[0m\n", i, j, GM->EdgeWeight[i][j]);
        }
    }
}

void outGraph(GraphMatrix *GM)//输出邻接矩阵
{
    int i, j;
    for(j = 0; j < GM->VertexNum; j++)
    {
        printf("\t%c", GM->Vertex[j]);
    }
    printf("\n");
    for(i = 0; i < GM->VertexNum; i++)
    {
        printf("%c", GM->Vertex[i]);
        for(j = 0; j < GM->VertexNum; j++)
        {
            if(GM->EdgeWeight[i][j] == MaxValue)
            {
                printf("\tz");//以z表示无穷大
            }
            else
            {
                printf("\t%d",GM->EdgeWeight[i][j]);//输出边的权值
            }
        }
        printf("\n");
    }
}

void deepTraverseOne(GraphMatrix *GM, int n)    //从第n个节点开始，深度遍历图
{
    int i;
    GM->isTrav[n] = 1;              //标记该顶点已处理过
    printf("->%c", GM->Vertex[n]);
    for(i = 0; i<GM->VertexNum; i++)
    {
        if(GM->EdgeWeight[n][i] != MaxValue && !GM->isTrav[n])
        {
            deepTraverseOne(GM, i);
        }
    }
}

void deepTraverse(GraphMatrix *GM)
{
    int i;
    for(i = 0; i < GM->VertexNum; i++)
    {
        GM->isTrav[i] = 0;//清除各顶点遍历标志
    }
    for(i = 0; i < GM->VertexNum; i++)
    {
        if(!GM->isTrav[i])
        {
            deepTraverseOne(GM, i);
        }
    }
    printf("\n");
}

void main()
{
    GraphMatrix GM;
    memset(&GM, 0x0, sizeof(GraphMatrix));
    printf("Input graph type.0:no dirction 1:dirction\n");
    scanf("%d", &GM.Gtype);
    printf("Input graph's vertex num\n");
    scanf("%d", &GM.VertexNum);
    printf("Input edge num.\n");
    scanf("%d", &GM.EdgeNum);
    clearEdgeWeight(&GM);
    createGraph(&GM);
    printf("\033[32mThis is the graph content output:\033[0m\n");
    outGraph(&GM);
    deepTraverse(&GM);

}