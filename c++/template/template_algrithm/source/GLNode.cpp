template <class T>
int GenList :: Depth (GLNode<T> *ls)
{
    if (ls == NULL) return 1;	//空表
    if (ls->tag == 0) return 0;	//原子元素
    GLNode<T> * temp = ls;  int max = 0;
    for (; temp; temp = temp->tp) {
        dep = Depth(temp->hp);	//求以temp->hp为头指针的子表深度
        if (dep > max)  max = dep;
    }
    return max+1;	//非空表的深度是各元素的深度的最大值加1
}
template <class T>
GLNode<T>* GenList::Copy(GLNode<T>  * ls) {
    GLNode<T> *q = NULL;
    if (ls != NULL) {
        q = new GLNode<T> (ls->tag, NULL);
        q->tag = ls->tag;
        if  (ls->tag == 0) q->data = ls->data;
        else { 
            q-> hp = Copy(ls->hp);          
            q-> tp = Copy(ls->tp);
        }
    }
    return q;
}
//若广义表非空, 则返回其第一个元素的值, 否则函数没有定义
template <class T>
GLNode<T> GenList::Head() {
    if (first == NULL) return NULL;
    else                  //非空表
        if first ->tag == 1 return first ->hp;
        else  return  first ->data;
}

template <class T>
GLNode<T> GenList::Tail()
{
    if (first == NULL) return NULL;
    else               //非空表      
        return  first ->tp;
}
