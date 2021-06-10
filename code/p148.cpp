//求矩阵乘积N= (*this)* M
template<class T>
void SparseMatrix<T>::Product(const SparseMatrix& M, const SparseMatrix& N)
{
    if (cols != M.mu) return ERROR;
    if (M.terms*terms! = 0) {				//N是非零矩阵
        Q.terms=0;
        for (arow=1; arow<=rows; ++arow) {				//处理每一行
            ctemp[] = 0;       				//当前行各元素累加器清零
            N.rpot[arow] = Q.terms+1; 
            //设置当前行第一个非零元素在三元组表中的位序   
            for (p= rpot[arow]; p<rpot[arow+1]; ++p) //对当前行中每一个非零元素
                brow=.data[p].col;				//找到对应元素在N中的行号
            if (brow < M.cols)  t = M.rpot[brow+1];
            else t = M.terms+1; 				//t指示该行中最后一个非零元素的位置
            for (q = M.rpot[brow]; q < t; ++q) {
                ccol = M.data[q].col;   				//乘积元素在q中列号
                ctemp[ccol] +=data[p].val *M.data[q].val;
            } 
        } //求得N中第crow(=arow)行的非零元素
        for (ccol = 1; ccol <= N.cols; ++ccol)		//压缩存储该行非零元素
            if (ctemp[ccol]) {				//该列元素为非零元素
                N.data[++N.terms] = { arow, ccol, ctemp[ccol] };
            }
    } 
}
