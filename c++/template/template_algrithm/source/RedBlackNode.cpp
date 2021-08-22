#include "RedBlackTree.h"
#include <iostream>
using namespace std;


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

void insert_case1(RedBlackNode<class Comparable>  n)
{
    if (n->parent == NULL)
        n->color = BLACK;
    else
        insert_case2 (n);
}
void insert_case2(RedBlackNode<class Comparable> n)
{
    if (n->parent->color == BLACK)
        return; /* 树仍有效 */
    else
        insert_case3 (n);
}
void insert_case3(RedBlackNode<class Comparable> n)
{
    if (Uncle(n) != NULL && Uncle(n)->color == RED) {
        n->parent->color = BLACK;
        Uncle(n)->color = BLACK;
        Grandparent(n)->color = RED;
        insert_case1(Grandparent(n));
    }
    else
        insert_case4(n);
}
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
node sibling(RedBlackNode<class Comparable> n)
{
    if (n == n->parent->left)
        return n->parent->right;
    else
        return n->parent->left;
}
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
void delete_case1(RedBlackNode<class Comparable> n)
{
    if (n->parent == NULL)
        return;
    else
        delete_case2(n);
}

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
