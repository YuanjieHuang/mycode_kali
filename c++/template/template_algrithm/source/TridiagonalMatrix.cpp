template<class Type>
class TridiagonalMatrix {
public : 
    TridiagonalMatrix(int size = 10)
    { n = size; t = new Type [3*n-2]; }
    ~TridiagonalMatrix() { delete [] t; }
    TridiagonalMatrix<T>& Store (const Type & x, int i, int j);
    Type Retrieve(int i, int j) const;
private:
    int n;	//矩阵维数
    Type *t;	//存储三对角矩阵的一维数组
};
//把x存为T(i, j)
template<class Type>
TridiagonalMatrix<Type>& TridiagonalMatrix<Type>::Store(const Type & x, int i, int j)
{   
    if (i < 1 || j < 1 || i > n || j > n) throw OutOfBounds();
    switch (i-j) {
        case 1:	//低对角线
            t[i-2] = x; break;
        case 0:	//主对角线
            t[n+i-2] = x; break;
        case -1:	//高对角线
            t[2*n+i-2] = x; break;
        default: if(x != 0) throw MustBeZero();
    }
    return *this;
}
//返回T(i, j)
template <class Type>
Type TridiagonalMatrix<Type>::Retrieve(int i, int j) const
{
    if (i < 1 || j < 1 || i > n || j > n) throw OutOfBounds();
    switch (i - j) {
        case 1:	//低对角线
          return t[i - 2];
        case 0:	//主对角线
          return t[n + i - 2];
        case -1:	//高对角线
          return t[2 * n + i - 2];
        default: return 0;
    }
}
