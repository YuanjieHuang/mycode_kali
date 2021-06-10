//把*this的转置结果送入b
template<class T>
void SparseMatrix<T>:: Transpose(SparseMatrix<T> &b) const
{ 
    if (terms > b.MaxTerms) throw NoMem();	//确信b有足够的空间
    //设置转置特征
    b.cols = rows;
    b.rows = cols;
    b.terms = terms;
    if (terms) {
        int *num, *cpot;
        num = new int[cols + 1];
        cpot = new int[rows + 1];
        //计算* this每一列的非零元素数
        for (int i = 1; i <= cols; i++) //初始化
            Num[i] = 0;
        for (int = 0; i < terms; i++)
            Num[data[i].col]++;
        //给出b中每一行的起始点
        cpot[1] = 0;
        for (int i = 2; i <= cols; i++)
            cpot[i] = cpot[i - 1] + Num[i-1];
        //执行转置操作
        for (int i = 0; i < terms; i++) {
            int j = cpot[data[i].col]++; //在b中的位置
            b.data[j].row = data[i].col;
            b.data[j].col = data[i].row;
            b.data[j].val = data[i].val;
        }
    }
}
