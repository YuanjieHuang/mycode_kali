#include <stdio.h>
#include <string.h>
#include "binaryTree.h"

int top=-1;//top变量时刻表示栈顶元素所在位置
//前序遍历使用的进栈函数
void push(BiTNode** a,BiTNode* elem){
    a[++top]=elem;
}
//弹栈函数
void pop( ){
    if (top==-1) {
        return ;
    }
    top--;
}
//拿到栈顶元素
BiTNode* getTop(BiTNode**a){
    return a[top];
}
//先序遍历非递归算法
void PreOrderTraverse(BiTree Tree){
    BiTNode* a[20];//定义一个顺序栈
    BiTNode * p;//临时指针
    push(a, Tree);//根结点进栈
    while (top!=-1) {
        p=getTop(a);//取栈顶元素
        pop();//弹栈
        while (p) {
            displayElem(p);//调用结点的操作函数
            //如果该结点有右孩子，右孩子进栈
            if (p->rchild) {
                push(a,p->rchild);
            }
            p=p->lchild;//一直指向根结点最后一个左孩子
        }
    }
}

void preOrderTraverse()
{
    // stack 
}
int main(){
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("先序遍历: \n");
    PreOrderTraverse(Tree);
}