#include <stdio.h>
#include <stdlib.h>
#include "Glist.h"

#ifdef __cplusplus
extern "C" {
#endif

Glist creatGlist(Glist C)
{
    //广义表C
    C=(Glist)malloc(sizeof(struct GLNode));
    C->tag=1;
    //表头原子‘a’
    C->ptr.hp=(Glist)malloc(sizeof(struct GLNode));
    C->ptr.hp->tag=0;
    C->ptr.hp->atom='a';
    //表尾子表（b,c,d）,是一个整体
    C->ptr.tp=(Glist)malloc(sizeof(struct GLNode));
    C->ptr.tp->tag=1;
    C->ptr.tp->ptr.hp=(Glist)malloc(sizeof(struct GLNode));
    C->ptr.tp->ptr.tp=NULL;
    //开始存放下一个数据元素（b,c,d）,表头为‘b’，表尾为（c,d）
    C->ptr.tp->ptr.hp->tag=1;
    C->ptr.tp->ptr.hp->ptr.hp=(Glist)malloc(sizeof(struct GLNode));
    C->ptr.tp->ptr.hp->ptr.hp->tag=0;
    C->ptr.tp->ptr.hp->ptr.hp->atom='b';
    C->ptr.tp->ptr.hp->ptr.tp=(Glist)malloc(sizeof(struct GLNode));
    //存放子表(c,d)，表头为c，表尾为d
    C->ptr.tp->ptr.hp->ptr.tp->tag=1;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(struct GLNode));
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->tag=0;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->atom='c';
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp=(Glist)malloc(sizeof(struct GLNode));
    //存放表尾d
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->tag=1;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(struct GLNode));
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->tag=0;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->atom='d';
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.tp=NULL;
    return C;
}

int GlistLength(Glist C) 
{
    int Number = 0;
    Glist P = C;
    while (P) 
    {
        Number++;
        P = P->ptr.tp;
    }
    return Number;
}

int GlistDepth(Glist C) 
{
    //如果表C为空表时，直接返回长度1；
    if (!C) 
    {
        return 1;
    }
    //如果表C为原子时，直接返回0；
    if (C->tag == 0) 
    {
        return 0;
    }
    int max = 0;//设置表C的初始长度为0；
    for (Glist pp = C; pp; pp = pp->ptr.tp) 
    {
        int dep = GlistDepth(pp->ptr.hp);
        if (dep > max) 
        {
            max = dep;//每次找到表中遍历到深度最大的表，并用max记录
        }
    }
    //程序运行至此处，表明广义表不是空表，由于原子返回的是0，而实际长度是1，所以，此处要+1；
    return max + 1;
}

void copyGlist(Glist C, Glist *T)
{
    //如果C为空表，那么复制表直接为空表 
    if (!C) 
    {
        *T=NULL;
    }
    else
    {
        *T=(Glist)malloc(sizeof(struct GLNode));//C不是空表，给T申请内存空间
        //申请失败，程序停止
        if (!*T) 
        {
            exit(0);
        }
        (*T)->tag=C->tag;//复制表C的tag值
        //判断当前表元素是否为原子，如果是，直接复制
        if (C->tag==0) 
        {
            (*T)->atom=C->atom;
        }
        else
        {//运行到这，说明复制的是子表
            copyGlist(C->ptr.hp, &((*T)->ptr.hp));//复制表头
            copyGlist(C->ptr.tp, &((*T)->ptr.tp));//复制表尾
        }
    }
}

int main() 
{
    printf("sizeof:Glist=%lu\n", sizeof(Glist));
    Glist C=NULL;
    C = creatGlist(C);
    printf("广义表的长度为：%d\n", GlistLength(C));
    printf("广义表的深度为：%d\n", GlistDepth(C));

    Glist T=NULL;
    copyGlist(C,&T);
    printf("%c\n",T->ptr.hp->atom);
    return 0;
}

#ifdef __cplusplus
}
#endif