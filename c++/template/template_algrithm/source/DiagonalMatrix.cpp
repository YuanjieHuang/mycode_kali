template <class Type>
class DiagonalMatrix  {
public: 
    DiagonalMatrix(int size=10)
    { n=size; d=new Type [n]; }
    ~DiagonalMatrix() { delete[] d; }	//析构函数
    DiagonalMatrix<Type>& Store(const Type &x, int i, int j);
    Type Retrieve(int i,int j)const;
private:
    int n;		//矩阵维数
    Type *d;	//存储对角元素的一维数组
};
//把x存为D(i,j)
template  <class Type>
DiagonalMatrix<Type>&DiagonalMatrix<Type>::Store(const Type &x,int i,int j)
{  
    if (i < 1 || j < 1 || i > n || j > n) throwOutOfBounds();
    if (i != j && x != 0)  throwMustBeZero();
    if (i == j)  d[i-1] = x;
    return *this;
}
//返回D(i,j)
template <class Type>
Type DiagonalMatrix<Type>::Retrieve(int i,int j) const
{   
    if (i < 1 || j < 1 || i > n || j > n) throwOutOfBounds();
    if (i == j) return d[i-1];
    else return 0;
}
