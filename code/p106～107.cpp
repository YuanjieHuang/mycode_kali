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
