//层次遍历
template<class T>
void BinaryTree<T>::LevelOrder(void(*Visit) (BinaryTreeNode<T> *u))
{  
    LinkedQueue < BinaryTreeNode<T>*> Q;
    BinaryTreeNode<T> *t;
    t = root;
    while (t) { //树非空时
        Visit(t);
        if (t->GetLeft()) Q.EnQueue(t->GetLeft());   //左孩子入队
        if (t->GetRight()) Q.EnQueue(t->GetRight()); //右孩子入队
        try
        { Q.DeQueue(t); }
        catch (OutOfBounds) 
        { return; }
    }
}
//非递归先序遍历二叉树
template<class T>
void BinaryTree<T>::PreOrderWithoutRecusion(BinaryTreeNode<T>* root)
{ 
    using std::stack;	
    stack<BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T>* pointer = root;		//保存输入参数	

    while(!aStack.empty() || pointer) {
        while (pointer) {
            Visit(pointer->data);			//访问当前结点
            aStack.push(pointer);			//当前结点地址入栈
            pointer = pointer->GetLeft();	//当前链接结构指向左孩子
        }
        if (!aStack.empty()) {	        		//左子树访问完毕, 转向访问右子树
            pointer = aStack.top();			//栈顶元素退栈                 
            aStack.pop();
            pointer = pointer->GetRight();	//当前链接结构指向右孩子
        } 
    } 
}
//非递归中序遍历二叉树
template<class T>
void BinaryTree<T>::InOrderWithoutRecusion(BinaryTreeNode<T>* root)	
{
    using std::stack;
    stack<BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T>* pointer = root;		//保存输入参数	

    While (!aStack.empty() || pointer) {

        while (pointer) {
            aStack.push(pointer);			//当前结点地址入栈
            pointer = pointer->GetLeft();	//当前链接结构指向左孩子
        }
        if (!aStack.empty()) {       		//左子树访问完毕, 转向访问右子树
            pointer = aStack.top();				
            Visit(pointer->data);	     	//访问当前结点
            Pointer = pointer->GetRight(); 	//当前链接结构指向右孩子
            aStack.pop();					//栈顶元素退栈                 
        } 
    } 
}
//非递归后序遍历二叉树
template<class T>
void BinaryTree<T>::PostOrderWithoutRecusion(BinaryTreeNode<T>* root)
{ 
    using std::stack;
    StackElement<T> element;
    stack<StackElement<T>> aStack;
    BinaryTreeNode<T>* pointer;
    if (NULL == root)
        return;		//空树即返回
    else pointer = root;
    while (true) {
        //进入左子树
        while (pointer! = NULL) {
            element.pointer = pointer;
            element.tag = LEFT;
            aStack.push(element);
            pointer = pointer->GetLeft();
        }

        if (!aStack.empty()){
            element = aStack.top();   	//弹出栈顶元素
            aStack.pop();
            pointer = element.pointer;
            if (element.tag == RIGHT) {	//从右子树回来
                Visit(pointer->data);	//访问当前结点
                if (aStack.empty())
                    return;
                else {
                    element = aStack.top();
                    aStack.pop();
                    pointer = element.pointer;
                }
            }
            else {	//从左子树回来 
                element.tag = RIGHT;
                aStack.push(element);
                pointer = pointer->GetRight();
            }
        }
    }
}
template <classT>
int Depth (BinaryTreeNode<T> *t)
{
    int depthLeft, depthRight, depthval;

    if (t == NULL) 
        depthval = 0;
    else {
        depthLeft = Depth(t->GetLeft());
        depthRight= Depth(t->GetRight());
        depthval = 1 +(depthLeft> depthRight? depthLeft:depthRight);
    }
    return depthval;
}
template <class T>
void CountLeaf(BinaryTreeNode<T> *t, int& count)
{
    if (t != NULL) {
        if (t->GetLeft() == NULL && t->GetRight() == NULL)  count++;
        CountLeaf(t->GetLeft(), count);  
        CountLeaf(t->GetRight(), count);
    }
}
enum Tags{LEFT,RIGHT};
template <class T>
class StackElement { 
public:
    BinaryTreeNode<T> *pointer;
    Tags tag;
};
template <class T>
TreeNode<T> *GetTreeNode(T item, BinaryTreeNode<T> *lptr = NULL, 
                             BinaryTreeNode<T> *rptr = NULL)
{
    TreeNode<T> *p;
    p = new TreeNode<T> (item, lptr, rptr);
    if (p == NULL)  
        exit(1);
    return p;
}

template <class T>
BinaryTreeNode<T> *CopyTree(BinaryTreeNode<T> *t)
{  
    BinaryTreeNode<T> *newlptr, *newrptr, *newnode;

    if (t == NULL)    return NULL;
    if (t->GetLeft() != NULL) 
        newlptr = CopyTree(t->GetLeft());
    else  newlptr = NULL;
    if (t->GetRight() != NULL) 
        newrptr = CopyTree(t->GetRight());
    else  newrptr = NULL;
    newnode = GetTreeNode(t->data, newlptr, newrptr);
    return newnode;
}
template class <T>
BinaryTreeNode<T> * CreatetreePreorderInorder(int* pre,int* in,int pl,int pr,
                                                	int il,int ir)
{   
    if (pl > pr) return NULL; //pl,pr 用来描述当前构造子树时先序序列的区间
    if (il > ir) return NULL; //il,ir 用来描述当前构造子树时中序序列的区间

    T val = pre[pl];
    BinaryTreeNode<T>* root = new BinaryTreeNode<T> (pre[pl]);

    int i = il;
    while ((in[i] != val) && (i <= ir))
        i++;

    root->SetLeft(CreatetreePreorderInorder(pre,in,pl+1,pl+i,il,i-1));
    root->SetRight(CreatetreePreorderInorder(pre,in,pl+i+1,pr,i+1,ir));
    return root;
}
按层次次序遍历以当前结点为根的树, 利用一个辅助队列 
templateclass T 
void TreeTLevelOrder() 
{ 
    Queue q; 
    if (!IsEmpty()) {  若树不为空树, 开始树的层次遍历 
        TreeNode p = current ; 	保存当前结点   
        q.QInsert(current);  		当前结点入队 
        while (!q.QEmpty()) { 
            current = q.QDelete(); 	出队一个结点, 设为当前结点
            visit(); 访问当前结点 
            FirstChild(); 
            将当前结点的所有子结点入队 
            while (!IsEmpty()) { 
                q.QInsert(current); 
                NextBrother(); 
            } 
        }       
        current = p; 恢复当前结点 
    }
} 
template<class T> 
void Tree<T>::PreOrder() 
{ 
    if (!IsEmpty()) { 
        visit(); 						//访问当前结点 
        TreeNode<T>*p = current;  		//保存当前结点 
        int k = FirstChild();         	//将当前结点定位到它的第一个子结点 
        //先根遍历当前结点的诸子树 
        while(k) { 
            PreOrder(); 
            k = NextBrother(); 
        } 
        current = p; //恢复当前指针 
    } 
}
