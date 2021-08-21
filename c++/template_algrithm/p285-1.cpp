node sibling(RedBlackNode<class Comparable> n)
{
    if (n == n->parent->left)
        return n->parent->right;
    else
        return n->parent->left;
}
