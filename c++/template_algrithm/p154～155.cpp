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
