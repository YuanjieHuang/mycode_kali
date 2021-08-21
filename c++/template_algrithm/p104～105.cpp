typedef  enum {ATOM, LIST} Elemtag; /*ATOM=0为单元素, LIST=1为子表*/
template <class T>
class GLNode {
    friend class Genlist;
private:
    Elemtag  tag;	//标志域, 用于区分元素结点和表结点
    union {	//元素结点和表结点的联合部分
        T  data;	//元素结点的值域
        GLNode<T>  *hp;	//表结点的表头指针
    };
    GLNode<T>  *tp;	//指向下一个结点 
};       
