template<class Type> 
class LowerMatrix {
public :
    LowerMatrix(int size = 10)
    { n = size; t = new Type [n*(n+1)/2]; }
    ~LowerMatrix() { delete [] t; }
    LowerMatrix<T>& Store(const Type& x, int i, int j);
    Type Retrieve(int i, int j) const;
private:
    int n;		//矩阵维数
    Type *t;	//存储下三角矩阵的一维数组
};
//把x存为L(i, j) 
template<class Type>
LowerMatrix<Type>& LowerMatrix<Type>::Store(const Type& x, int i, int j)
{ 
    if (i < 1 || j < 1 || i > n || j > n) throw OutOfBounds();
    //当且仅当I >= j 时(i,j) 位于下三角
    if (i >= j) t[i*(i-1)/2+j-1] = x;
    else if (x != 0) throw MustBeZero();
    return *this;
}
//返回L(i, j)
template <class Type>
Type LowerMatrix<T>::Retrieve(int i, int j) const
{  
    if (i < 1 || j < 1 || i > n || j > n) throw OutOfBounds();
    //当且仅当i >= j 时(i,j)位于下三角
    if (i >= j) return t[i*(i-1)/2+j-1];
    else return 0;
}
