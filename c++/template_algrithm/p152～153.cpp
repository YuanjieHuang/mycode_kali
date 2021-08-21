template<class T>
void SMatrix<T>::CreateMatrix()
{
    if ((rowhead != NULL) || (colnum != NULL)) FreeMem();
    cout << "输入矩阵的行数:";
    cin >> rownum;
    cout << endl;
    cout << "输入矩阵的列数:";
    cin >> colnum;
    cout << endl;
    MallocMem(rownum, colnum);	//为行列指针收集空间
    
    cout << "请输入矩阵的元素, 格式<行, 列, 数据>+回车, 结束输入请输入-1" << endl;
    int i, j;
    T ele;
    while (1)  {
        cin >> i;
        if(i == -1) break;
        cin >> j;
        cin >> ele;
        if ((i > rownum) || (j > colnum) || (i < 1) || (j < 1))  {
            cout << "不正确的行, 列号" << endl;
            continue;
        }
        OLNode<T>* temp = new OLNode<T>();
        temp->row = i;
        temp->col = j;
        temp->element = ele;
        //处理行指针
        OLNode<T>* t2 = rowhead[i];
        OLNode<T>* t1 = NULL;
        while((t2 != NULL) && (j > t2->col))  {	//查找位置 
            t1 = t2;
            t2 = t2->right;
        }
        if ((t2! = NULL) && (t2->col == j))  
            t2->element = temp->element;		//修改值
        else  {			//插入新的指针
            t1->right = temp;
            temp->right = t2;
        }
        //处理列指针
        t2 = colhead[j];
        t1 = NULL;
        while ((t2 != NULL) && (i > t2->row))  {	//查找位置 
            t1 = t2;
            t2 = t2->down;
        }
        if ((t2 != NULL) && (t2->row == i))  { 
            t2->element=temp->element;	//修改值
        }
        else  {	//插入新的指针
            t1->down = temp;
            temp->down = t2;
        }
    }
}
