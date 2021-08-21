//稀疏矩阵的构造函数
template<class T> SparseMatrix<T>::SparseMatrix(int maxTerms)
{ 
    if (maxTerms < 1) throw BadInitializers();
    MaxTerms = maxTerms;
    data= new Term<T> [MaxTerms];
    terms = rows = cols = 0;
}
