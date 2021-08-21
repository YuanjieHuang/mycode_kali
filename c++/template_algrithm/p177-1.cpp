template <classT>
int Depth (BinaryTreeNode<T> *t)
{
    int depthLeft, depthRight, depthval;

    if (t == NULL) 
        depthval = 0;
    else {
        depthLeft = Depth(t->GetLeft());
        depthRight= Depth(t->GetRight());
        depthval = 1 +(depthLeft> depthRight? depthLeft:depthRight);
    }
    return depthval;
}
