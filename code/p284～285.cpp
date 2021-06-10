void insert_case5(RedBlackNode<class Comparable> n)
{
    n->parent->color = BLACK;
    Grandparent(n)->color = RED;
    if (n == n->parent->left && n->parent == Grandparent(n)->left) {
        rotateWithRightChild(Grandparent(n));
    }
    else {  //此处, n == n->parent->right && n->parent == Grandparent(n)->right
        rotateWithLeftChild(Grandparent(n));
    }
}
