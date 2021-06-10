RedBlackNode<class Comparable> * 
RedBlackNode<class Comparable>::Grandparent(RedBlackNode  n)
{
    return n->parent->parent;
}

RedBlackNode<class Comparable> *
RedBlackNode<class Comparable>::Uncle(RedBlackNode n)
{
    if (n->parent == grandparent(n)->left)
        return Grandparent(n)->right;
    else
        return Grandparent(n)->left;
}

