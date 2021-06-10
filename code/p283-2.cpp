void insert_case2(RedBlackNode<class Comparable> n)
{
    if (n->parent->color == BLACK)
        return; /* 树仍有效 */
    else
        insert_case3 (n);
}
