/*
双亲表示法采用顺序表（也就是数组）存储普通树，
其实现的核心思想是：顺序存储各个节点的同时，给各节点附加一个记录其父节点位置的变量。
注意，根节点没有父节点（父节点又称为双亲节点），因此根节点记录父节点位置的变量通常置为 -1。
*/
    #include<stdio.h>
    #include<stdlib.h>
    #define MAX_SIZE 20
    typedef char ElemType;//宏定义树结构中数据类型
    typedef struct Snode  //结点结构
    {
        ElemType data;//树中结点的数据类型
        int parent;//结点的父结点在数组中的位置下标
    }PTNode;
    typedef struct {
        PTNode tnode[MAX_SIZE];//存放树中所有结点
        int n;//根的位置下标和结点数
    }PTree;
    PTree InitPNode(PTree tree)
    {
        int i, j;
        char ch;
        printf("请输出节点个数:\n");
        scanf("%d", &(tree.n));
        printf("请输入结点的值其双亲位于数组中的位置下标:\n");
        for (i = 0; i < tree.n; i++)
        {
            getchar();
            scanf("%c %d", &ch, &j);
            tree.tnode[i].data = ch;
            tree.tnode[i].parent = j;
        }
        return tree;
    }
    void FindParent(PTree tree)
    {
        char a;
        int isfind = 0;
        printf("请输入要查询的结点值:\n");
        getchar();
        scanf("%c", &a);
        for (int i = 0; i < tree.n; i++) {
            if (tree.tnode[i].data == a) {
                isfind = 1;
                int ad = tree.tnode[i].parent;
                printf("%c的父节点为 %c,存储位置下标为 %d", a, tree.tnode[ad].data, ad);
                break;
            }
        }
        if (isfind == 0) {
            printf("树中无此节点");
        }
    }
    int main()
    {
        PTree tree;
        for (int i = 0; i < MAX_SIZE; i++) {
            tree.tnode[i].data = " ";
            tree.tnode[i].parent = 0;
        }
       
        tree = InitPNode(tree);
        FindParent(tree);
        return 0;
    }