    #include <stdio.h>
    #include <stdlib.h>
/* 
线索二叉树:在遍历的同时，使用二叉树中空闲的内存空间记录某些结点的前趋和后继元素的位置（不是全部）。
存储密度指的是数据本身所占的存储空间和整个结点结构所占的存储量之比。
每一棵二叉树上，很多结点都含有未使用的指向NULL的指针域。除了度为2的结点，度为 1 的结点，有一个空的指针域；叶子结点两个指针域都为NULL。
    规律：在有 n 个结点的二叉链表中必定存在 n+1 个空指针域。
线索二叉树实际上就是使用这些空指针域来存储结点之间前趋和后继关系的一种特殊的二叉树。
*/
    #define TElemType char//宏定义，结点中数据域的类型
    //枚举，Link为0，Thread为1
    typedef enum {
        Link,
        Thread
    }PointerTag;
    //结点结构构造
    typedef struct BiThrNode {
        TElemType data;//数据域
        struct BiThrNode* lchild, *rchild;//左孩子，右孩子指针域
        PointerTag Ltag, Rtag;//标志域，枚举类型
    }BiThrNode, *BiThrTree;
    BiThrTree pre = NULL;
    //采用前序初始化二叉树
    //中序和后序只需改变赋值语句的位置即可
    void CreateTree(BiThrTree * tree) {
        char data;
        scanf("%c", &data);
        if (data != '#') {
            if (!((*tree) = (BiThrNode*)malloc(sizeof(BiThrNode)))) {
                printf("申请结点空间失败");
                return;
            }
            else {
                (*tree)->data = data;//采用前序遍历方式初始化二叉树
                (*tree)->Ltag = Link;
                (*tree)->Rtag = Link;
                CreateTree(&((*tree)->lchild));//初始化左子树
                CreateTree(&((*tree)->rchild));//初始化右子树
            }
        }
        else {
            *tree = NULL;
        }
    }
    //中序对二叉树进行线索化
    void InThreading(BiThrTree p) {
        //如果当前结点存在
        if (p) {
            InThreading(p->lchild);//递归当前结点的左子树，进行线索化
            //如果当前结点没有左孩子，左标志位设为1，左指针域指向上一结点 pre
            if (!p->lchild) {
                p->Ltag = Thread;
                p->lchild = pre;
            }
            //如果 pre 没有右孩子，右标志位设为 1，右指针域指向当前结点。
            if (pre && !pre->rchild) {
                pre->Rtag = Thread;
                pre->rchild = p;
            }
            pre = p;//pre指向当前结点
            InThreading(p->rchild);//递归右子树进行线索化
        }
    }
    //中序遍历线索二叉树
    void InOrderThraverse_Thr(BiThrTree p)
    {
        while (p)
        {
            //一直找左孩子，最后一个为中序序列中排第一的
            while (p->Ltag == Link) {
                p = p->lchild;
            }
            printf("%c ", p->data);  //操作结点数据
            //当结点右标志位为1时，直接找到其后继结点
            while (p->Rtag == Thread && p->rchild != NULL)
            {
                p = p->rchild;
                printf("%c ", p->data);
            }
            //否则，按照中序遍历的规律，找其右子树中最左下的结点，也就是继续循环遍历
            p = p->rchild;
        }
    }
    int main() {
        BiThrTree t;
        printf("输入前序二叉树:\n");
        CreateTree(&t);
        InThreading(t);
        printf("输出中序序列:\n");
        InOrderThraverse_Thr(t);
        return 0;
    }