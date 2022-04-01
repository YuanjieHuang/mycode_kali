struct link
{
    int data;
    struct  link* next;
};

link * head_reverse(link * head)
{
    link *newHead = NULL, tmp = NULL;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        temp->next = new_head;
        new_head = temp;

    }
    return new_head;
}

list* local_reverse(list* head)
{
    list *beg = NULL, *end = NULL;
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    beg = head;
    end = head->next;
    while (end != NULL)
    {
        beg->next = end->next;
        end->next = beg;
        beg = end;
        end = beg->next;
    }
    return beg;
    
}

int haveRing(link *head)
{
    if(head == NULL || head->next ==NULL)
    {
        return 0;
    }
    link *h1 = head->next;
    link *h2 = head;
    while (h1)
    {
        if(h1 == h2)
        {
            return 1;
        }
        else
        {
            h1 = h1->next;
            if(h1 == NULL)
            {
                return 0;
            }
            else
            {
                h1 = h1->next;
                h2 = h2->next;
            }
        }
    }
    return 0;
}