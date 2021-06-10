//弧结点
class ArcNode  {
protected:
    int  tailvex, headvex;		//该弧的尾和头顶点的位置
    ArcNode  *hlink, *tlink;	//分别为弧头相同和弧尾相同的弧的指针域
    InfoType  *info;        	//该弧相关信息的指针
public:
       ...
}

//顶点结点
template<class T>
class VexNode 
{
protected:
    List<ArcNode>  *firstin, *firstout; //分别为入弧和出弧的链表
public:
    T  vertex;
     ...

} 

//图
template<class T>
class Graph
{
private:
    SqList<VexNode> OrthList;
    int vexnum, arcnum;    //图的当前顶点数和弧数
  
    ...
} 
