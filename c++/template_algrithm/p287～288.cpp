void delete_case5(RedBlackNode<class Comparable> n)
{
    if (n == n->parent->left && sibling(n)->color == BLACK && 
        sibling(n)->left->color == RED &&
        sibling(n)->right->color == BLACK)  {
        sibling(n)->color = RED;
        sibling(n)->left->color = BLACK;
        rotateWithRightChild(sibling(n));
    }
    else if (n == n->parent->right && sibling(n)->color == BLACK &&
             sibling(n)->right->color == RED &&
             sibling(n)->left->color == BLACK)  {
        sibling(n)->color = RED;
        sibling(n)->right->color = BLACK;
        rotateWithLefttChild(sibling(n));
    }
    delete_case6(n);
}
