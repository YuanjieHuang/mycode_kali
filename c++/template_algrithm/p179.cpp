template class <T>
BinaryTreeNode<T> * CreatetreePreorderInorder(int* pre,int* in,int pl,int pr,
                                                	int il,int ir)
{   
    if (pl > pr) return NULL; //pl,pr 用来描述当前构造子树时先序序列的区间
    if (il > ir) return NULL; //il,ir 用来描述当前构造子树时中序序列的区间

    T val = pre[pl];
    BinaryTreeNode<T>* root = new BinaryTreeNode<T> (pre[pl]);

    int i = il;
    while ((in[i] != val) && (i <= ir))
        i++;

    root->SetLeft(CreatetreePreorderInorder(pre,in,pl+1,pl+i,il,i-1));
    root->SetRight(CreatetreePreorderInorder(pre,in,pl+i+1,pr,i+1,ir));
    return root;
}
