void delete_case1(RedBlackNode<class Comparable> n)
{
    if (n->parent == NULL)
        return;
    else
        delete_case2(n);
}

