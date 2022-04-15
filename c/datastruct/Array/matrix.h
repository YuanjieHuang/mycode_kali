#ifndef matrix_h
#define matrix_h

#define ElemType int
#define MAXSIZE 12500
#define MAXRC 100

typedef struct
{
    int i, j;//行，列
    ElemType e;//元素值
}Triple;

#define number 10

typedef struct
{
    Triple  data[MAXSIZE + 1];
    int rpos[MAXRC + 1];//每行第一个非零元素在data数组中的位置
    int mu, nu, tu;//行数，列数，元素个数
}RLSMatrix;//行逻辑链接的顺序表

typedef struct 
{
    Triple data[10];
    int n, m, num;//行数，列数，元素个数
}TSMatrix;//三元组顺序表


typedef struct OLNode
{
    int i, j, e; //矩阵三元组i代表行 j代表列 e代表当前位置的数据
    struct OLNode *right, *down; //指针域 右指针 下指针
}OLNode, *OLink;

typedef struct
{
    OLink *rhead, *chead; //行和列链表头指针
    int mu, nu, tu;  //矩阵的行数,列数和非零元的个数
}CrossList;//十字链表存储稀疏矩阵

#endif