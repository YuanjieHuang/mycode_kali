//重载<<
//把*this 送至输出流
template <class T>
ostream& operator<<(ostream& out, const SparseMatrix<T>& x)
{   
    //输出矩阵的特征
    out << "rows = " << x.rows << " columns = " << x.cols << endl;
    out << "nonzero terms = " << x.terms << endl;
    //输出非零元素, 每行1个
    for (int i = 0; i < x.terms; i++)
        out << "data(" << x.data[i].row << ',' << x.data[i].col << ") = "
            << x.data[i].val << endl;
    return out;
}

//重载>>
//输入一个稀疏矩阵
template<class T>
istream& operator>>(istream& in, SparseMatrix<T>& x)
{  
    //输入矩阵的特征
    cout << "Enter number of rows, columns, and terms" << endl;
    in >> x.rows >> x.cols >> x.terms;
    if (x.terms > x.MaxTerms) throw NoMem();
    //输入矩阵元素
    for (int i = 0; i < x.terms; i++) {
        cout << "Enter row, column, and value of term " << (i + 1) << endl;
        in >> x.data[i].row >> x.data[i].col >> x.data[i].val;
    }
    return in;
}
