void delete_case3(RedBlackNode<class Comparable> n)
{
    if (n->parent->color == BLACK && sibling(n)->color == BLACK &&
        sibling(n)->left->color == BLACK && sibling(n)->right->color == BLACK)  {
        sibling(n)->color = RED;
        delete_case1(n->parent);
    }
    else
        delete_case4(n);
}
