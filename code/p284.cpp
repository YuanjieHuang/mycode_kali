void insert_case4(RedBlackNode<class Comparable> n)
{
    if (n == n->parent->right && n->parent == Grandparent(n)->left) {
        rotateWithLeftChild(n->parent);
        n = n->left;
    }
    else if (n == n->parent->left && n->parent == Grandparent(n)->right) {
        rotateWithRightChild(n->parent);
        n = n->right;
    }
    insert_case5(n);
}

