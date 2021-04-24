    typedef struct GLNode{
        int tag;//标志域
        union{
            char atom;//原子结点的值域
            struct{
                struct GLNode * hp,*tp;
            }ptr;//子表结点的指针域，hp指向表头；tp指向表尾
        };
    }*Glist;
        Glist creatGlist(Glist C){
        //广义表C
        C=(Glist)malloc(sizeof(Glist));
        C->tag=1;
        //表头原子‘a’
        C->ptr.hp=(Glist)malloc(sizeof(Glist));
        C->ptr.hp->tag=0;
        C->ptr.hp->atom='a';
        //表尾子表（b,c,d）,是一个整体
        C->ptr.tp=(Glist)malloc(sizeof(Glist));
        C->ptr.tp->tag=1;
        C->ptr.tp->ptr.hp=(Glist)malloc(sizeof(Glist));
        C->ptr.tp->ptr.tp=NULL;
        //开始存放下一个数据元素（b,c,d）,表头为‘b’，表尾为（c,d）
        C->ptr.tp->ptr.hp->tag=1;
        C->ptr.tp->ptr.hp->ptr.hp=(Glist)malloc(sizeof(Glist));
        C->ptr.tp->ptr.hp->ptr.hp->tag=0;
        C->ptr.tp->ptr.hp->ptr.hp->atom='b';
        C->ptr.tp->ptr.hp->ptr.tp=(Glist)malloc(sizeof(Glist));
        //存放子表(c,d)，表头为c，表尾为d
        C->ptr.tp->ptr.hp->ptr.tp->tag=1;
        C->ptr.tp->ptr.hp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(Glist));
        C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->tag=0;
        C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->atom='c';
        C->ptr.tp->ptr.hp->ptr.tp->ptr.tp=(Glist)malloc(sizeof(Glist));
        //存放表尾d
        C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->tag=1;
        C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(Glist));
        C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->tag=0;
        C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->atom='d';
        C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.tp=NULL;
        return C;
    }
#if 0
    typedef struct GLNode{
        int tag;//标志域
        union{
            int atom;//原子结点的值域
            struct GLNode *hp;//子表结点的指针域，hp指向表头
        };
        struct GLNode * tp;//这里的tp相当于链表的next指针，用于指向下一个数据元素
    }*Glist;

        Glist creatGlist(Glist C){
        C=(Glist)malloc(sizeof(Glist));
        C->tag=1;
        C->hp=(Glist)malloc(sizeof(Glist));
        C->tp=NULL;
        //表头原子a
        C->hp->tag=0;
        C->atom='a';
        C->hp->tp=(Glist)malloc(sizeof(Glist));
        C->hp->tp->tag=1;
        C->hp->tp->hp=(Glist)malloc(sizeof(Glist));
        C->hp->tp->tp=NULL;
        //原子b
        C->hp->tp->hp->tag=0;
        C->hp->tp->hp->atom='b';
        C->hp->tp->hp->tp=(Glist)malloc(sizeof(Glist));
        //原子c
        C->hp->tp->hp->tp->tag=0;
        C->hp->tp->hp->tp->atom='c';
        C->hp->tp->hp->tp->tp=(Glist)malloc(sizeof(Glist));
        //原子d
        C->hp->tp->hp->tp->tp->tag=0;
        C->hp->tp->hp->tp->tp->atom='d';
        C->hp->tp->hp->tp->tp->tp=NULL;
        return C;
    }
#endif