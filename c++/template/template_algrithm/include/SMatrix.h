//行, 列和元素
class Element  {
public:
    int row;
    int col;
    int data;
};

//首先定义结点类, T是结点存储的数据类型
//如果是头结点则不存储任何数值
template<class T> class SMatrix;

template<class T>
class OLNode  {
    friend SMatrix<T>;
private:
    int row,col;	//矩阵的行和列
    T element;	//矩阵中存储的数据
    OLNode<T>* right, *down;	//指向下一个结点的指针
public:
    OLNode(){ right=NULL;down=NULL; };
};

//稀疏矩阵
template<class T>
class SMatrix  {
private:
    int rownum,colnum;		//行列数
    void CreateMatrix(CArray<Element, Element>&Data);	//只能局部使用
public:
    OLNode<T> **rowhead, **colhead;		//矩阵的第一个非零元素
    SMatrix();
    void MallocMem(int row, int col);		//为矩阵收集内存
    int GetRownum();
    int GetColnum();
    void CreateMatrix();	//建立矩阵
    void PrintAll();
    void FreeMem();
    SMatrix<int> * MatrixAdd(SMatrix<int> *Ha, SMatrix<int>*Hb);
};
