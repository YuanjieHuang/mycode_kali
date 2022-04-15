#include<stdio.h>
#include<stdlib.h>
#include "matrix.h"

CrossList CreateMatrix_OL(CrossList M);
CrossList AddSMatrix(CrossList M, CrossList N);
void display(CrossList M);

void main()
{
    CrossList M, N;
    M.rhead = NULL;
    M.chead = NULL;
    N.rhead = NULL;
    N.chead = NULL;
    printf("输入测试矩阵M:\n");
    M = CreateMatrix_OL(M);
    printf("输入测试矩阵N:\n");
    N = CreateMatrix_OL(N);
    M = AddSMatrix(M, N);
    printf("矩阵相加的结果为:\n");
    display(M);
}
    //创建系数矩阵M,采用十字链表存储表示
CrossList CreateMatrix_OL(CrossList M)
{
    int m,n,t;
    int i,j,e;
    OLNode *p,*q;//定义辅助变量
    scanf("%d%d%d",&m,&n,&t);  //输入矩阵的行列及非零元的数量
    //初始化矩阵的行列及非零元的数量
    M.mu=m;
    M.nu=n;
    M.tu=t;
    if(!(M.rhead=(OLink*)malloc((m+1)*sizeof(OLink)))||!(M.chead=(OLink*)malloc((n+1)*sizeof(OLink))))
    {
        printf("初始化矩阵失败");
        exit(0); //初始化矩阵的行列链表
    }
    for(i=1;i<=m;i++)
    {
        M.rhead[i]=NULL; //初始化行
    }
    for(j=1;j<=n;j++)
    {
        M.chead[j]=NULL; //初始化列
    }
    for(scanf("%d%d%d",&i,&j,&e);0!=i;scanf("%d%d%d",&i,&j,&e)) //输入三元组 直到行为0结束
    {
        if(!(p=(OLNode*)malloc(sizeof(OLNode))))
        {
            printf("初始化三元组失败");
            exit(0); //动态生成p
        }
        p->i=i;
        p->j=j;
        p->e=e; //初始化p
        if(NULL==M.rhead[i]||M.rhead[i]->j>j)
        {
            p->right=M.rhead[i];
            M.rhead[i]=p;
        }
        else
        {
            for(q=M.rhead[i];(q->right)&&q->right->j<j;q=q->right);
            p->right=q->right;
            q->right=p;
        }
        
        if(NULL==M.chead[j]||M.chead[j]->i>i)
        {
            p->down=M.chead[j];
            M.chead[j]=p;
        }
        else
        {
            for (q=M.chead[j];(q->down)&& q->down->i<i;q=q->down);
            p->down=q->down;
            q->down=p;
        }
    }
    return M;
}

CrossList AddSMatrix(CrossList M,CrossList N)
{
    OLNode * pa,*pb;//新增的两个用于遍历两个矩阵的结点
    OLink * hl=(OLink*)malloc(M.nu*sizeof(OLink));//用于存储当前遍历的行为止以上的区域每一个列的最后一个非0元素的位置。
    OLNode * pre=NULL;//用于指向pa指针所在位置的此行的前一个结点
    //遍历初期，首先要对hl数组进行初始化，指向每一列的第一个非0元素
    for (int j=1; j<=M.nu; j++) 
    {
        hl[j]=M.chead[j];
    }
    //按照行进行遍历
    for (int i=1; i<=M.mu; i++) 
    {
        //遍历每一行以前，都要pa指向矩阵M当前行的第一个非0元素；指针pb也是如此，只不过遍历对象为矩阵N
        pa=M.rhead[i];
        pb=N.rhead[i];
        //当pb为NULL时，说明矩阵N的当前行的非0元素已经遍历完。
        while (pb!=NULL) 
        {
            //创建一个新的结点，每次都要复制一个pb结点，但是两个指针域除外。（复制的目的就是排除指针域的干扰）
            OLNode * p=(OLNode*)malloc(sizeof(OLNode));
            p->i=pb->i;
            p->j=pb->j;
            p->e=pb->e;
            p->down=NULL;
            p->right=NULL;
            
            //第一种情况
            if (pa==NULL||pa->j>pb->j) 
            {
                //如果pre为NULL，说明矩阵M此行没有非0元素
                if (pre==NULL) 
                {
                    M.rhead[p->i]=p;
                }
                else
                {
//由于程序开始时pre肯定为NULL，所以，pre指向的是第一个p的位置，在后面的遍历过程中，p指向的位置是逐渐向后移动的，所有，pre肯定会在p的前边
                    pre->right=p;
                }
                p->right=pa;
                pre=p;
                //在链接好行链表之后，链接到对应列的列链表中的相应位置
                if (!M.chead[p->j]||M.chead[p->j]->i>p->i) 
                {
                    p->down=M.chead[p->j];
                    M.chead[p->j]=p;
                }
                else
                {
                    p->down=hl[p->j]->down;
                    hl[p->j]->down=p;
                }
                //更新hl中的数据
                hl[p->j]=p;
            }
            else
            {
                //第二种情况，只需要移动pa的位置，继续判断pa和pb的位置，一定要有continue
                if (pa->j<pb->j) 
                {
                    pre=pa;
                    pa=pa->right;
                    continue;
                }
                //第三、四种情况，当行标和列标都想等的情况下，需要讨论两者相加的值的问题
                if (pa->j==pb->j) 
                {
                    pa->e+=pb->e;
                    //如果为0，摘除当前结点，并释放所占的空间
                    if (pa->e==0) 
                    {
                        if (pre==NULL) 
                        {
                            M.rhead[pa->i]=pa->right;
                        }
                        else
                        {
                            pre->right=pa->right;
                        }
                        p=pa;
                        pa=pa->right;
                        if (M.chead[p->j]==p) 
                        {
                            M.chead[p->j]=hl[p->j]=p->down;
                        }
                        else
                        {
                            hl[p->j]->down=p->down;
                        }
                        free(p);
                    }
                }
            }
            pb=pb->right;
        }
    }
    //用于输出矩阵三元组的功能函数
    display(M);
    return M;
}

void display(CrossList M) 
{
    printf("输出测试矩阵:\n");
    printf("M:\n---------------------\ni\tj\te\n---------------------\n");
    for (int i = 1; i <= M.nu; i++)
    {
        if (NULL != M.chead[i])
        {
            OLink p = M.chead[i];
            while (NULL != p)
            {
                printf("%d\t%d\t%d\n", p->i, p->j, p->e);
                p = p->down;
            }
        }
    }
}