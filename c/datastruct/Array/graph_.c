/*
邻接表实现
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20//图最大顶点数

typedef struct EdgeNode//单链表中节点的类型
{
    int adjvex;//该边指向的顶点在顺序表中的位置
  struct  EdgeNode * next;//下一条边
}EdgeNode;
typedef struct VertexNode//顶点类型
{
    int     data;//顶点中的数据信息
    EdgeNode * firstEdge;//指向单链表，即指向第一条边
}VertexNode;

int visited[5]={0};
void creatGraph(int n, VertexNode G[])
{
    int i,e;
    EdgeNode *p,*q;
    printf("Input the information of the vertex\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&G[i]);
        G[i].firstEdge = NULL;

    }
    for(i=0;i<n;i++)
    {
        printf("Input the edges of the %dth vertex\n",i);
        scanf("%d",&e);
        G[i].firstEdge = NULL;
        while (e != -1)
        {
            p = (EdgeNode *)malloc(sizeof(EdgeNode));
            p->next = NULL;
            p->adjvex = e;
            if(G[i].firstEdge == NULL)
            {
               G[i].firstEdge = p; 
            }
            else
            {
                q->next = p;
                q = p;
                scanf("%d",&e);
            }
        }
    }
}

int firstAdj(VertexNode G[], int v)
{
    if(G[v].firstEdge != NULL)
    {
        return (G[v].firstEdge)->adjvex;
    }
    return -1;
}

int nextAdj(VertexNode G[], int v)
{
    EdgeNode *p;
    p = G[v].firstEdge;
    while (p != NULL)
    {
       if(visited[p->adjvex])
       {
           p = p->next;
       }
       else
       {
           return p->adjvex;
       }
    }
    return -1;
    
}

void DFS(VertexNode G[], int v)//DeepFisrtSeach
{
    int w;
    printf("G[v}:%d", G[v]);
    visited[v] = 1;
    w = firstAdj(G,v);
    while (w != -1)
    {
        if(visited[w] == 0)
        {
            DFS(G,w);
            w = nextAdj(G,v);
        }
    }
}

void main()
{
    VertexNode G[5];
    creatGraph(5,G);
    DFS(G,0);

}