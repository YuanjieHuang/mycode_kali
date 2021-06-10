void delete_case4(RedBlackNode<class Comparable> n)
{
    if (n->parent->color == RED && sibling(n)->color == BLACK &&
        sibling(n)->left->color == BLACK &&
        sibling(n)->right->color == BLACK)  {
        sibling(n)->color = RED;
        n->parent->color = BLACK;
    }
    else
        delete_case5(n);
}
