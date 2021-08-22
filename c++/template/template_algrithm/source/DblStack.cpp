#include <assert.h>

template <class Type> 
class DblStack {	
private:
	int top[2], bot[2];	//双栈的栈顶指针和栈底指针
	Type *elements;		//栈数组
	int m;					//栈最大可容纳元素个数
public:
	DblStack(int sz =10);					//初始化双栈, 总容量m的默认值为10
	~DblStack() { delete[] elements; }		//析构函数
	void DblPush(const Type& x, int i);		//把x插入到栈i的栈顶
	int DblPop(int i);					//退掉位于栈i栈顶的元素
	Type * DblGetTop(int i);				//返回栈i栈顶元素的值
	int IsEmpty(int i) const
	{ return top[i] == bot[i]; }		//判栈i空否, 空则返回1, 否则返回0 
	int IsFull() const 
	{ return top[0]+1 == top[1]; }		//判栈满否, 满则返回1, 否则返回0
	void MakeEmpty(int i); 			//清空栈i的内容
};

//建立一个最大尺寸为sz的空栈, 若分配不成功则错误处理
template <class Type> 
DblStack<Type> :: DblStack(int sz) 
					: m(sz), top[0] (-1), bot[0](-1), top[1](sz), bot[1](sz)
{	
	elements = new Type[m];			//创建栈的数组空间
	assert (elements != NULL);			//断言: 动态存储分配成功与否
}

template <class Type> 
void DblStack<Type> :: DblPush(const Type& x, int i) 
{   
	//如果IsFull()为真, 则报错, 否则把x插入到栈i的栈顶
	assert (!IsFull());			//断言: 栈满则出错处理, 停止执行
	if (i == 0) 
		elements[++top[0]] = x;	//0号栈情形：栈顶指针先加1, 然后按此地址进栈
	else 
		elements[--top[1]] = x; 	//1号栈情形：栈顶指针先减1, 然后按此地址进栈
}

template <class Type> 
int DblStack<Type> :: DblPop(int i) 
{
	//如果IsEmpty(i)为真, 则不执行退栈, 返回0; 否则退掉位于栈i栈顶的元素, 返回1
	if (IsEmpty(i)) return 0;			//判栈空否, 若栈空, 则函数返回0
	if (i == 0) top[0]--;				//0号栈情形：栈顶指针减1
	else top[1]++; 					//1号栈情形：栈顶指针加1
	return 1;
}

template <class Type> 
Type * DblStack<Type> :: DblGetTop(int i) 
{
	//若栈不空, 则函数返回该栈栈顶元素的地址
	if (IsEmpty(int i)) return NULL;	//判栈i空否, 若栈空, 则函数返回空指针
	return& elements[top[i]];			//返回栈顶元素的值
}	

template <class Type>
void MakeEmpty(int i) 
{
	if (i == 0) top[0] = bot[0] = -1;
	else top[1] = bot[1] = m; 
}

