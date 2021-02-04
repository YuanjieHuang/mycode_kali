/*
树结构
层次括号法：
1.根节点放入一对圆括号中；
2.根节点的子树由左至右的顺序放入括号中；
3.对子树做上述同样的处理。
*/
/*
1.初始化二叉树
2.添加节点
3 查找节点
4 获取左子树
5 获取右子树
6 判断空树
7 计算二叉树深度
8 清空二叉树
9 显示节点数据
10 遍历二叉树

*/
#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
#define MAXLEN 20
typedef char DATA;
typedef struct MYTREE
{
    DATA data;
    struct MYTREE *left;
    struct MYTREE *right;
}myTree;

myTree *treeLeftNode(myTree *treeNode);
myTree *treeFindNode(myTree *treeNode, DATA data);

myTree *initTree()
{
    myTree *node;
    if(node = ((myTree *)malloc(sizeof(myTree))))
    {
        printf("please input the data of root node\n");
        scanf("%s", &node->data);
        node->left = NULL;
        node->right = NULL;
        if(node != NULL)
        {
            return node;
        }
        else
        {
            return NULL;
        }
    }
    return NULL;
}

void addTreeNode(myTree *treeNode)
{
    myTree *pnode ,*parent;
    DATA data;
    int menusel;
    if(pnode =((myTree *)malloc(sizeof(myTree))))
    {
        printf("\033[35mInput the node data you need to add.\033[0m\n");
        fflush(stdin);
        scanf("%s",&pnode->data);
        pnode->left = NULL;
        pnode->right =NULL;

        printf("please input this node's parent data:\n");
        scanf("%s", &data);
        parent = treeFindNode(treeNode, data);

        if(!parent)
        {
            printf("Did not find this parent!\n");
            free(pnode);
            return;
        }
        printf("Input:\t1.add this node to left subtree\n 2.add this node to right subtree\n");
        do
        {
            // menusel = getc(stdin);
            fflush(stdin);
            scanf("%d",&menusel);
            printf("The stdin char is:%d", menusel);
            // menusel -= '0';
            if(menusel == 1 || menusel == 2)
            {
                if(parent == NULL)
                {
                    printf("parent node not exist,please set parent firstly.\n");
                }
                else
                {
                    switch (menusel)
                    {
                    case 1:
                        {
                            printf("Enter do recursive\n");
                            if(parent->left)
                            {
                                printf("left subtree is not empty.\n");
                            }
                            else
                            {
                                parent->left = pnode;
                            }
                            break;
                        }
                        
                    case 2:
                        if(parent->right)
                        {
                            printf("left subtree is not empty.\n");
                        }
                        else
                        {
                            parent->right = pnode;
                        }
                        break;
                    
                    default:
                        printf("uneffective data.\n");
                    }
                }
            }


        }while(menusel != 1 && menusel != 2);
    }
}

myTree *treeFindNode(myTree *treeNode, DATA data)
{
    myTree *ptr;
    if(treeNode == NULL)
    {
        return NULL;
    }
    else
    {
        if(treeNode->data == data)
        {
            return treeNode;
        }
        else
        {
            if(ptr = treeFindNode(treeNode->left, data))
            {
                return ptr;
            }
            else if(ptr = treeFindNode(treeNode->right, data))
            {
                return ptr;
            }
            else
            {
                return NULL;
            }
        }
    }
}

myTree *getLeftNode(myTree *treeNode)
{
    if(treeNode)
    {
        return treeNode->left;
    }
    else
    {
        return NULL;
    }
}

myTree *getRightNode(myTree *treeNode)
{
    if(treeNode)
    {
        return treeNode->right;
    }
    else
    {
        return NULL;
    }
}

int isEmptyTree(myTree *treeNode)
{
    if(treeNode)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int calTreeDepth(myTree *treeNode)
{
    int depleft, depright;
    if(treeNode == NULL)
    {
        return 0;
    }
    else
    {
        depleft  = calTreeDepth(treeNode->left);//递归
        depright = calTreeDepth(treeNode->right);
        if(depleft > depright)
        {
            return depleft + 1;
        }
        else
        {
            return depright + 1;
        }
    }
}

void clearTree(myTree *treeNode)
{
    if(treeNode)
    {
        clearTree(treeNode->left);
        clearTree(treeNode->right);
        free(treeNode);
        treeNode = NULL;
    }
}

void showTreeNodeData(myTree *treeNode)
{
    printf("Tree node data:%c\n", treeNode->data);          
}

void levelTraverseTree(myTree *treeNode, void (*showTreeNodeData)(myTree *p))//按层遍历
{
    myTree *p;
    myTree *q[MAXLEN];
    int head = 0, tail = 0;
    if(treeNode)
    {
        tail = (tail + 1)%MAXLEN;
        q[tail] = treeNode;
    }
    while(head != tail)
    {
        head = (head + 1) % MAXLEN;//循环队列方式
        p = q[head];
        showTreeNodeData(p);
        if(p->left != NULL)
        {
            tail = (tail + 1)%MAXLEN;
            q[tail] = p->left;
        }
        if(p->right != NULL)
        {
            tail = (tail + 1)%MAXLEN;
            q[tail] = p->right;
        }
    }
}

void DLRTraverse(myTree *treeNode, void (*showTreeNodeData)(myTree *p))//左序遍历
{
    if(treeNode)
    {
        showTreeNodeData(treeNode);
        DLRTraverse(treeNode->left,showTreeNodeData);
        DLRTraverse(treeNode->right,showTreeNodeData);
    }
}

void LDRTraverse(myTree *treeNode, void (*showTreeNodeData)(myTree *p))
{
    if(treeNode)
    {
        
        DLRTraverse(treeNode->left,showTreeNodeData);
        showTreeNodeData(treeNode);
        DLRTraverse(treeNode->right,showTreeNodeData);
        
    }
}

void LRDTraverse(myTree *treeNode, void (*showTreeNodeData)(myTree *p))//后序遍历
{
    if(treeNode)
    {
        
        DLRTraverse(treeNode->left,showTreeNodeData);
        DLRTraverse(treeNode->right,showTreeNodeData);
        showTreeNodeData(treeNode);
    }
}

void main()
{
    myTree *root = NULL;
    char menusel, index;
    void (*treeNodeData)(myTree *tereNode);
    treeNodeData = showTreeNodeData;//指向具体操作的函数
    root = initTree();
    do
    {
        printf("please choose a menu to add treeNodes.\n");
        printf("0.quit\t1.Add tree node.\n");
        // menusel = getc(stdin);
        fflush(stdin);
        scanf("%c",&menusel);
        switch (menusel)
        {
        case '1':
            addTreeNode(root);
            break;
        case '0':
            break;
        default:
            ;
        }
    }while(menusel != '0');
    
    
    do
    {
        // fflush(stdout);
        setbuf(stdin, NULL);
        printf("please choose a menu to add treeNodes.\n");
        setbuf(stdin, NULL);
        fflush(stdin);
        // scanf("%c",&index);
        index = getc(stdin);
        switch (index)
        {
            case '0'://测试先后中序遍历
                printf("LDR\n");
                LDRTraverse(root,treeNodeData);
                printf("\n");
                break;
            case '1':
                printf("DLR\n");
                DLRTraverse(root, treeNodeData);
                printf("\n");
                break;
            case '2':
                printf("LRD\n");
                LRDTraverse(root, treeNodeData);
                printf("\n");
                break;
            case '3':
                printf("level\n");
                levelTraverseTree(root, treeNodeData);
                printf("\n");
                break;
            default:
                    ;
        }            
    }while (index != '0');
    printf("The tree depth is :%d", calTreeDepth(root));
    clearTree(root);
    root = NULL;
}