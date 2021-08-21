int sum_list(struct Lnode *l)
{
    if (l == NULL)
        return 0;
    return l->data + sum_list(l->next);
}
