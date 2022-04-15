#include <stdio.h>
#include <string.h>
#include "binaryTree.h"

int top=-1;//top变量时刻表示栈顶元素所在位置

//弹栈函数
void pop( ){
    if (top==-1) {
        return ;
    }
    top--;
}
//后序遍历非递归算法
//后序遍历使用的进栈函数
void postpush(SNode *a,SNode sdata){
    a[++top]=sdata;
}
//后序遍历函数
void PostOrderTraverse(BiTree Tree){
    SNode a[20];//定义一个顺序栈
    BiTNode * p;//临时指针
    int tag;
    SNode sdata;
    p=Tree;
    while (p||top!=-1) {
        while (p) {
            //为该结点入栈做准备
            sdata.p=p;
            sdata.tag=0;//由于遍历是左孩子，设置标志位为0
            postpush(a, sdata);//压栈
            p=p->lchild;//以该结点为根结点，遍历左孩子
        }
        sdata=a[top];//取栈顶元素
        pop();//栈顶元素弹栈
        p=sdata.p;
        tag=sdata.tag;
        //如果tag==0，说明该结点还没有遍历它的右孩子
        if (tag==0) {
            sdata.p=p;
            sdata.tag=1;
            postpush(a, sdata);//更改该结点的标志位，重新压栈
            p=p->rchild;//以该结点的右孩子为根结点，重复循环
        }
        //如果取出来的栈顶元素的tag==1，说明此结点左右子树都遍历完了，可以调用操作函数了
        else{
            displayElem(p);
            p=NULL;
        }
    }
}

int main(){
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("\n后序遍历: \n");
    PostOrderTraverse(Tree);
}