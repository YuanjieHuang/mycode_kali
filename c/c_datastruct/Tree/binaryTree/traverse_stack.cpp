#include <iostream>
#include <stack>
#include <queue>
#include "binaryTree.h"
using namespace std;

void levelTraverse() 
{
    printf("\n层序遍历: \n");
    BiTree tree;
    //初始化二叉树
    CreateBiTree(&tree);
    BiTNode * p;
    //采用顺序队列，初始化创建队列数组
    queue<BiTree> a;
    //根结点入队
    a.push(tree);
    //当队头和队尾相等时，表示队列为空
    while(!a.empty()) 
    {
        //队头结点出队
        p=a.front();
        a.pop();
        displayElem(p);
        //将队头结点的左右孩子依次入队
        if (p->lchild!=NULL) 
        {
            a.push(p->lchild);
        }
        if (p->rchild!=NULL) 
        {
            a.push(p->rchild);
        }
    }
}

//先序遍历非递归算法
void PreOrderTraverse(BiTree Tree)
{
    stack<BiTNode *> a;
    BiTNode * p;//临时指针
    a.push(Tree);//根结点进栈
    while (!a.empty()) 
    {
        p=a.top();//取栈顶元素
        a.pop();//弹栈
        while (p) 
        {
            displayElem(p);//调用结点的操作函数
            //如果该结点有右孩子，右孩子进栈
            if (p->rchild) 
            {
                a.push(p->rchild);
            }
            p=p->lchild;//一直指向根结点最后一个左孩子
        }
    }
}

//中序遍历非递归算法
void InOrderTraverse1(BiTree Tree)
{
    stack<BiTNode *> a;
    BiTNode * p;//临时指针
    a.push(Tree);//根结点进栈
    while(! a.empty()) 
    {//top!=-1说明栈内不为空，程序继续运行
        while ((p = a.top()) && p)
        {//取栈顶元素，且不能为NULL
            a.push(p->lchild);//将该结点的左孩子进栈，如果没有左孩子，NULL进栈
        }
        a.pop();//跳出循环，栈顶元素肯定为NULL，将NULL弹栈
        if (! a.empty()) 
        {
            p=a.top();//取栈顶元素
            a.pop();//栈顶元素弹栈
            displayElem(p);
            a.push(p->rchild);//将p指向的结点的右孩子进栈
        }
    }
}
//中序遍历实现的另一种方法
void InOrderTraverse2(BiTree Tree)
{
    stack<BiTNode *> a;
    BiTNode * p;//临时指针
    p=Tree;
    //当p为NULL或者栈为空时，表明树遍历完成
    while (p || !a.empty()) 
    {
        //如果p不为NULL，将其压栈并遍历其左子树
        if (p) 
        {
            a.push(p);
            p=p->lchild;
        }
        //如果p==NULL，表明左子树遍历完成，需要遍历上一层结点的右子树
        else
        {
            p=a.top();
            a.pop();
            displayElem(p);
            p=p->rchild;
        }
    }
}

//后序遍历函数
void PostOrderTraverse(BiTree Tree)
{
    stack<SNode> a;
    BiTNode * p;//临时指针
    int tag;
    SNode sdata;
    p=Tree;
    while (p || !a.empty()) 
    {
        while (p) 
        {
            //为该结点入栈做准备
            sdata.p=p;
            sdata.tag=0;//由于遍历是左孩子，设置标志位为0
            a.push(sdata);//压栈
            p=p->lchild;//以该结点为根结点，遍历左孩子
        }
        sdata=a.top();//取栈顶元素
        a.pop();//栈顶元素弹栈
        p=sdata.p;
        tag=sdata.tag;
        //如果tag==0，说明该结点还没有遍历它的右孩子
        if (tag==0) 
        {
            sdata.p=p;
            sdata.tag=1;
            a.push(sdata);//更改该结点的标志位，重新压栈
            p=p->rchild;//以该结点的右孩子为根结点，重复循环
        }
        //如果取出来的栈顶元素的tag==1，说明此结点左右子树都遍历完了，可以调用操作函数了
        else
        {
            displayElem(p);
            p=NULL;
        }
    }
}

int main()
{
    BiTree Tree;
    levelTraverse(); 

    CreateBiTree(&Tree);
    printf("\n先序遍历: \n");
    PreOrderTraverse(Tree);
    
    printf("\n中序遍历算法1: \n");
    InOrderTraverse1(Tree);
    printf("\n中序遍历算法2: \n");
    InOrderTraverse2(Tree);

    CreateBiTree(&Tree);
    printf("\n后序遍历: \n");
    PostOrderTraverse(Tree);
    return 0;
}