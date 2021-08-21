void insert_case1(RedBlackNode<class Comparable>  n)
{
    if (n->parent == NULL)
        n->color = BLACK;
    else
        insert_case2 (n);
}
