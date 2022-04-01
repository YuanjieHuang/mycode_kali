#ifndef binary_tree_h
#define binary_tree_h


#define TElemType int

//构造结点的结构体
typedef struct BiTNode
{
    TElemType data;//数据域
    struct BiTNode *lchild,*rchild;//左右孩子指针
}BiTNode,*BiTree;

// #define TElemType char//宏定义，结点中数据域的类型
//枚举，Link为0，Thread为1
typedef enum 
{
    Link,
    Thread
}PointerTag;
//结点结构构造
typedef struct BiThrNode 
{
    TElemType data;//数据域
    struct BiThrNode* lchild, *rchild;//左孩子，右孩子指针域
    PointerTag Ltag, Rtag;//标志域，枚举类型
}BiThrNode, *BiThrTree;

//后序遍历
typedef struct SNode{
    BiTree p;
    int tag;
}SNode;

#ifdef __cplusplus
extern "C" {
#endif
void CreateBiTree(BiTree *T);
void displayElem(BiTNode* elem);

#ifdef __cplusplus
}
#endif

#endif