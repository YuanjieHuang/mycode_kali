void delete_case2(RedBlackNode<class Comparable> n)
{
    if (sibling(n)->color == RED) {
        n->parent->color = RED;
        sibling(n)->color = BLACK;
        if (n == n->parent->left)
            rotateWithLeftChild(n->parent);
        else
            rotateWithRightChild(n->parent);
    }
    delete_case3(n);
}
