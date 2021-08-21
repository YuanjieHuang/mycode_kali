typedef  enum {ATOM, LIST} Elemtag;	//ATOM=0为单元素, LIST=1为子表
template <class T>
class GLNode {
    friend class Genlist;
private:
    Elemtag  tag;	//标志域, 用于区分元素结点和表结点
    union {			//元素结点和表结点的联合部分
        T  data;		//data是元素结点的值域
        struct {
            GLNode<T>  *hp, *tp	//ptr是表结点的指针域, ptr.hp和ptr.tp分别
        }ptr;		//指向表头和表尾
                                     
    };
};					//广义表类型

template <class T>
class GenList {		//广义表类定义     
private:
    GLNode<T> *first;	//广义表头指针
public:
    Genlist();		//构造函数
    ~GenList();		//析构函数 
    GLNode<T> & Head();	//返回表头元素
    GenList& Tail();	//返回表尾
    GLNode <T> *First();	//返回第一个元素
    GLNode<T>  *Copy(GLNode<T>  *ls);	//复制一个ls指示的无共享非递归表
    int depth(GLNode<T>  *ls);	//计算由ls指示的非递归表的深度
    int equal(GLNode <T> *s, GLNode <T> *t);	//比较以s和t为表头的表是否相等
    void Remove(GLNode <T> *ls);	//释放以ls为表头结点的广义表
    ...
};
