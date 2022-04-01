#include <stdio.h>
#include "binaryTree.h"

//初始化队头和队尾指针开始时都为0
int front=0,rear=0;
//入队函数
void EnQueue(BiTree *a,BiTree node){
    a[rear++]=node;
}
//出队函数
BiTNode* DeQueue(BiTNode** a){
    return a[front++];
}
//输出函数
void displayNode(BiTree node){
    printf("%d ",node->data);
}
int main() {
    BiTree tree;
    //初始化二叉树
    CreateBiTree(&tree);
    BiTNode * p;
    //采用顺序队列，初始化创建队列数组
    BiTree a[20];
    //根结点入队
    EnQueue(a, tree);
    //当队头和队尾相等时，表示队列为空
    while(front<rear) {
        //队头结点出队
        p=DeQueue(a);
        displayNode(p);
        //将队头结点的左右孩子依次入队
        if (p->lchild!=NULL) {
            EnQueue(a, p->lchild);
        }
        if (p->rchild!=NULL) {
            EnQueue(a, p->rchild);
        }
    }
    return 0;
}