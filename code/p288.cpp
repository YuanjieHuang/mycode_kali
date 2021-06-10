void delete_case6(RedBlackNode<class Comparable> n)
{
    sibling(n)->color = n->parent->color;
    n->parent->color = BLACK;
    if (n == n->parent->left) {
        //此处, sibling(n)->color == BLACK && sibling(n)->right->color == RED
        sibling(n)->right->color = BLACK;
        rotateWithLeftChild (n->parent);
    }
    else  {
        //此处, sibling(n)->color == BLACK && sibling(n)->left->color == RED
        sibling(n)->left->color = BLACK;
        rotateWithRightChild(n->parent);
    }
}
