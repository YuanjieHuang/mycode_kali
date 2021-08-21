//把*this的转置结果送入b
template<c lass T>
void SparseMatrix<T>:: Transpose(SparseMatrix<T> &b) const 
{  
    //确信b有足够的空间
    if (terms > b.MaxTerms) throw NoMem();
    //设置转置特征
    b.cols = rows;
    b.rows = cols;
    b.terms = terms;
    if (terms) {
        j=1;
        for (int i = 1; i <= cols; i++)			//对于每一列
            for (int t = 0; t < terms;t++)		//比较每个非0元素
                if (data[t].col == i) {
                   b.data[j].row = data[t].col;
                   b.data[j].col = data[t].row;
                   b.data[j].value = data[t].val;
                   j++;
                }
    } 
}
