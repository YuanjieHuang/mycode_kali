//前提： n至少有一个非空孩子
void delete_one_child(RedBlackNode<class Comparable> n)
{
    node child = (is_leaf(n->right)) ? n->left ： n->right;
    replace_node(n, child);
    if (n->color == BLACK) {
        if (child->color == RED)
            child->color = BLACK;
        else
            delete_case1(child);
    }
    free(n);
}
