#include <stdio.h>
#include <stdlib.h>
#include "link.h"

//双链表的创建函数
line* initLine(line * head);
//输出双链表的函数
void display(line * head);
//双链表的创建
line* initLine(line * head);
//双链表插入元素，add表示插入位置
line * insertLine(line * head,int data,int add);
//双链表删除指定元素
line * delLine(line * head,int data);
//双链表中查找指定元素
int selectElem(line * head,int elem);
//双链表中更改指定位置节点中存储的数据，add表示更改位置
line *amendElem(line * p,int add,int newElem);
//输出双链表的实现函数
void display(line * head);

int main() 
{
    //创建一个头指针
    line * head=NULL;
    //调用链表创建函数
    head=initLine(head);
    //输出创建好的链表
    display(head);
    //显示双链表的优点
    printf("链表中第 4 个节点的直接前驱是：%d",head->next->next->next->prior->data);

    head=NULL;
    //创建双链表
    head=initLine(head);
    display(head);
    //在表中第 3 的位置插入元素 7
    head=insertLine(head, 7, 3);
    display(head);
    //表中删除元素 2
    head=delLine(head, 2);
    display(head);
    printf("元素 3 的位置是：%d\n",selectElem(head,3));
    //表中第 3 个节点中的数据改为存储 6
    head = amendElem(head,3,6);
    display(head);
    return 0;
}

line* initLine(line * head)
{
    //创建一个首元节点，链表的头指针为head
    head=(line*)malloc(sizeof(line));
    //对节点进行初始化
    head->prior=NULL;
    head->next=NULL;
    head->data=1;
    //声明一个指向首元节点的指针，方便后期向链表中添加新创建的节点
    line * list=head;
    for (int i=2; i<=5; i++) 
    {
        //创建新的节点并初始化
        line * body=(line*)malloc(sizeof(line));
        body->prior=NULL;
        body->next=NULL;
        body->data=i;
        //新节点与链表最后一个节点建立关系
        list->next=body;
        body->prior=list;
        //list永远指向链表中最后一个节点
        list=list->next;
    }
    //返回新创建的链表
    return head;
}

void display(line * head)
{
    line * temp=head;
    while (temp) 
    {
        //如果该节点无后继节点，说明此节点是链表的最后一个节点
        if (temp->next==NULL) 
        {
            printf("%d\n",temp->data);
        }
        else
        {
            printf("%d <-> ",temp->data);
        }
        temp=temp->next;
    }
}

line * insertLine(line * head,int data,int add)
{
    //新建数据域为data的结点
    line * temp=(line*)malloc(sizeof(line));
    temp->data=data;
    temp->prior=NULL;
    temp->next=NULL;
    //插入到链表头，要特殊考虑
    if (add==1) 
    {
        temp->next=head;
        head->prior=temp;
        head=temp;
    }
    else
    {
        line * body=head;
        //找到要插入位置的前一个结点
        for (int i=1; i<add-1; i++) 
        {
            body=body->next;
        }
        //判断条件为真，说明插入位置为链表尾
        if (body->next==NULL) 
        {
            body->next=temp;
            temp->prior=body;
        }
        else
        {
            body->next->prior=temp;
            temp->next=body->next;
            body->next=temp;
            temp->prior=body;
        }
    }
    return head;
}

line * delLine(line * head,int data)
{
    line * temp=head;
    //遍历链表
    while (temp) 
    {
        //判断当前结点中数据域和data是否相等，若相等，摘除该结点
        if (temp->data==data) 
        {
            temp->prior->next=temp->next;
            temp->next->prior=temp->prior;
            free(temp);
            return head;
        }
        temp=temp->next;
    }
    printf("链表中无该数据元素");
    return head;
}

//head为原双链表，elem表示被查找元素
int selectElem(line * head,int elem)
{
//新建一个指针t，初始化为头指针 head
    line * t=head;
    int i=1;
    while (t) 
    {
        if (t->data==elem) 
        {
            return i;
        }
        i++;
        t=t->next;
    }
    //程序执行至此处，表示查找失败
    return -1;
}

//更新函数，其中，add 表示更改结点在双链表中的位置，newElem 为新数据的值
line *amendElem(line * p,int add,int newElem)
{
    line * temp=p;
    //遍历到被删除结点
    for (int i=1; i<add; i++) 
    {
        temp=temp->next;
    }
    temp->data=newElem;
    return p;
}