#include <stdio.h>

struct Link
{
    int data;
    struct Link *next;
}

Link* head_reverse(Link* head)
{
    Link *new_head = NULL;
    Link* tmp = NULL;
    if(head == NULL || head->next ==NULL)
    {
        return head;
    }
    
    while (head != NULL)
    {
        temp = head;
        //将 temp 从 head 中摘除
        head = head->next;
        //将 temp 插入到 new_head 的头部
        temp->next = new_head;
        new_head = temp;
    }
    return new_head;
    
}

Link* reverse(Link *head)
{
    Link *beg = NULL, *end = NULL;
    beg = head;
    end = head->next;
    if(beg == NULL || end == NULL)
    {
        return head;
    }
    while (end->next != NULL)
    {
        beg->next = end->next;

        end->next = head;
        head = end;

        end = beg->next;
    }
    return head;
    
}

int main()
{
    return 0;
}