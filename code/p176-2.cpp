template <class T>
void CountLeaf(BinaryTreeNode<T> *t, int& count)
{
    if (t != NULL) {
        if (t->GetLeft() == NULL && t->GetRight() == NULL)  count++;
        CountLeaf(t->GetLeft(), count);  
        CountLeaf(t->GetRight(), count);
    }
}
