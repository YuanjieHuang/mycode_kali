#include <stdio.h>
#include <string.h>
#include "binaryTree.h"
//先序遍历
void PreOrderTraverse(BiTree T)
{
    if (T) 
    {
        displayElem(T);//调用操作结点数据的函数方法
        PreOrderTraverse(T->lchild);//访问该结点的左孩子
        PreOrderTraverse(T->rchild);//访问该结点的右孩子
    }
    //如果结点为空，返回上一层
    return;
}

    //中序遍历
void INOrderTraverse(BiTree T)
{
    if (T) 
    {
        INOrderTraverse(T->lchild);//遍历左孩子
        displayElem(T);//调用操作结点数据的函数方法
        INOrderTraverse(T->rchild);//遍历右孩子
    }
    //如果结点为空，返回上一层
    return;
}

//后序遍历
void PostOrderTraverse(BiTree T)
{
    if (T) 
    {
        PostOrderTraverse(T->lchild);//遍历左孩子
        PostOrderTraverse(T->rchild);//遍历右孩子
        displayElem(T);//调用操作结点数据的函数方法
    }
    //如果结点为空，返回上一层
    return;
}

int main() 
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("先序遍历: \n");
    PreOrderTraverse(Tree);
    printf("中序遍历算法: \n");
    INOrderTraverse(Tree);
    printf("后序遍历: \n");
    PostOrderTraverse(Tree);
}