//稀疏矩阵的构造函数
template<class T> SparseMatrix<T>::SparseMatrix(int maxTerms)
{ 
    if (maxTerms < 1) throw BadInitializers();
    MaxTerms = maxTerms;
    data= new Term<T> [MaxTerms];
    terms = rows = cols = 0;
}
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