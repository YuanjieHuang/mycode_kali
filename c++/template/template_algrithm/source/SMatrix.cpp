#include "SMatrix.h"
#include <iostream>
using namespace std;
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
template <class T>
SMatrix<int>* SMatrix<T>::MatrixAdd(SMatrix<int>*Ha,SMatrix<int>*Hb)
{
     OLNode<T>*p,*q,*pa,*pb,*ca,*cb,*qa;
     if (Ha->GetRownum() != Hb->GetRownum()
        || Ha-> GetColnum()!= Hb-> GetColnum()) return NULL;
     i =1;
     ca = Ha->rowhead[i];			//ca初始指向A矩阵中第一行表头结点
     cb = Hb->rowhead[i];			//cb初始指向B矩阵中第一行表头结点
     do {
         pa = ca->right;			//pa指向A矩阵当前行中第一个结点
         qa = ca;					//qa是pa的前驱
         pb = cb->right;			//pb指向B矩阵当前行中第一个结点
         while (pb->col != 0)  {	//当前行没有处理完
              if (pa->col < pb->col && pa->col != 0)  {	//第3种情况
                  qa = pa;
                  pa = pa->right;
              }
              else
                  if (pa->col > pb->col || pa->col == 0)  {	//第4种情况
                      p = new OLNode<T> ();
                      p->row = pb->row;  p->col = pb->col;  p->val = pb->val;
                      p->right = pa; qa->right = p;	//新结点插入*pa的前面
                      pa = p;
                      //新结点还要插到列链表的合适位置, 先找位置, 再插入
                      q = Find_JH(Ha, p->col);		//从列链表的头结点找起
                      while (q->down->row != 0 && q->down->row<p->row)
                          q = q->down; 
                      p->down = q->down;			//插在*q的后面
                      q->down = p;
                      pb = pb->right;
              } 	 
              else  {								//第1、2种情况
                  x = pa->val+ pb->val;
                  if (x == 0)  {					//第2种情况
                      qa->right = pa->right;		//从行链中删除
                      //还要从列链中删除, 找*pa的列前驱结点
                      q = Find_JH (Ha,pa->col);		//从列链表的头结点找起
                      while (q->down->row < pa->row)
                          q = q->down; 
                      q->down = pa->down;
                      deltete pa;
                      pa = qa;
                  } 
                  else  {  //第1种情况
                      pa->val = x;
                      qa = pa;
                  } 
                  pa = pa->right;
                  pb = pb->right;
              }
        } 
        i++;
        ca = Ha->rowhead[i];		//ca指向A中下一行的表头结点
        cb = Hb->rowhead[i];		//cb指向B中下一行的表头结点
    } while (i <= Ha->GetRownum())	//当还有未处理完的行则继续
    return  Ha;
} 
