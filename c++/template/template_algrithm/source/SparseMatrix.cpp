<class T>
class Term {
private:
    int row, col; 
    T val;
};

template<class T>
class SparseMatrix  {
    friend ostream& operator<< (ostream&, const SparseMatrix<T>&);
    friend istream& operator>> (istream&, SparseMatrix<T>&);
public:
    SparseMatrix(int maxTerms = 10);
    ~SparseMatrix() { delete [] a; }
    void Transpose(SparseMatrix<T> &b) const;
    void Add(const SparseMatrix<T> &b, SparseMatrix<T> &c) const;
private:
    void Append(const Term<T>& t);
    int rows, cols;	//矩阵维数
    int terms;	//非零元素数目
    Term<T> *data;	//存储非零元素的数组
    int MaxTerms;	//数组a的大小;
};
