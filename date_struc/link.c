#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 20
#define false 0
#define true 1

typedef struct 
{
    char key[10];
    char name[20];
    int age;
}Data;
typedef struct Node
{
    Data nodeData;
    struct Node *nextNode;
}Link;

Link *addEnd(Link *head, Data nodeData)//末尾追加节点
{
    Link *node, *htemp;
    if(!(node = (Link *)malloc(sizeof(Link))))
    {
        printf("Apply buffer failed!\n");
        return NULL;
    }
    else
    {
        node->nodeData = nodeData;
        node->nextNode = NULL;
        if(head == NULL)
        {
            head = node;
            return head;
        }
        htemp = head;
        while (htemp->nextNode != NULL)
        {
            htemp = htemp->nextNode;
        }
        htemp->nextNode = node;
        return head;
        
    }
}

Link *addFirst(Link *head, Data nodeData)
{
    Link *node;
    if(!(node = (Link *)malloc(sizeof(Link))))
    {
        printf("apply buffer failure\n");
        return NULL;
    }
    else
    {
        node->nodeData = nodeData;
        node->nextNode = head;
        head = node;
        return head;
    }
}

Link *findNodeByKey(Link *head, char *key)
{
    Link *htemp;
    htemp = head;
    while(htemp)
    {
        if(strcmp(htemp->nodeData.key, key) == 0)
        {
            return htemp;
        }
        htemp = htemp->nextNode;
    }
    return NULL;
}

Link *insertNodeByKey(Link *head, char *findkey, Data nodeDate)
{
    Link *node, *nodeTemp;
    if(!(node = (Link *)malloc(sizeof(Link))))
    {
        printf("apply buffer failure\n");
        return NULL;
    }
    node->nodeData = nodeDate;
    nodeTemp = findNodeByKey(head, findkey);
    if(nodeTemp)
    {
        node->nextNode = nodeTemp;
        nodeTemp->nextNode = node;
    }
    else
    {
        printf("unfind correct site\n");
        free(node);
    }
    return head;
}

int deleteNode(Link *head, char *key)
{
    Link *node, *htemp;
    htemp = head;
    node = head;
    while (htemp)
    {
        if(strcmp(htemp->nodeData.key, key) == 0)
        {
            node->nextNode = htemp->nextNode;
            free(htemp);
            return 1;
        }
        else
        {
            node = htemp;
            htemp = htemp->nextNode;
        }
        
    }
    return 0;  
}

int getListLen(Link *head)
{
    Link *htemp;
    int len = 0;
    htemp = head;
    while (htemp)
    {
     len++;
     htemp = htemp->nextNode;
    }
    return len;
}

void showNode(Link node)
{
    printf("key:%s name:%s age:%d", node.nodeData.key, node.nodeData.name, node.nodeData.age);
}
void showAllNodes(Link *head)
{
    Link *htemp;
    Data nodaData;
    htemp = head;
    int index = 1;
    printf("The list node number is %d\n", getListLen(head));
    while(htemp)
    {
        nodaData = htemp->nodeData;
        printf("Node%d:(%s,%s,%d)", index, htemp->nodeData.key, htemp->nodeData.name, htemp->nodeData.age);
        index++;
        htemp = htemp->nextNode;
    }
}

void main()
{
    Link *node, *head = NULL;
    Data nodeData;
    char key[10], findkey[10];
    printf("Test list.Input data of the list,rule:key name age\n");
    do//iput 0 to exit while circulation.
    {
        fflush(stdin);
        scanf("%s",nodeData.key);
        if(strcmp(nodeData.key, "0") == 0)
        {
            break;
        }
        else
        {
            scanf("%s%d",nodeData.name, &nodeData.age);
            head = addEnd(head,nodeData);
        }
    } while (1);
    showAllNodes(head);

    Link *searchedNode;
    printf("\nInput a keyword for searching node");
    scanf("%s", key);
    searchedNode = findNodeByKey(head, key);
    showNode(*searchedNode);
    

}