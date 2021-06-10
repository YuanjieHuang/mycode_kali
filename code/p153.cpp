template<class T>
void SMatrix<T>::MallocMem(int row,int col)
{
    rownum = row;
    colnum = col;
    rowhead = new OLNode<T>*[row+1];
    colhead = new OLNode<T>*[col+1];
    for (int count=0; count<=row; count++)  {	//初始化为头结点
        rowhead[count] = new OLNode<T>();
        rowhead[count]->row = -1;
        rowhead[count]->col = -1;
    }
    for (count=0; count<=col; count++)  {
        colhead[count] = new OLNode<T>();
        colhead[count]->row = -1;
        colhead[count]->col = -1;
    }
}
