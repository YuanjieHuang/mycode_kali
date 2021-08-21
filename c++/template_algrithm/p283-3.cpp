void insert_case3(RedBlackNode<class Comparable> n)
{
    if (Uncle(n) != NULL && Uncle(n)->color == RED) {
        n->parent->color = BLACK;
        Uncle(n)->color = BLACK;
        Grandparent(n)->color = RED;
        insert_case1(Grandparent(n));
    }
    else
        insert_case4(n);
}
