void Initialize(int n)  //初始化n个类, 每个类仅有一个元素
{   
    node = new EquivNode[n + 1];
    for (int e = 1; e <= n; e++) {
        node[e].E = e;
        node[e].link = 0;
        node[e].size = 1;
    }
}

void Union(int i, int j)  //合并类i和类j, 使i代表较小的类
{   
    if (node[i].size > node[j].size)
        swap (i, j);
    //改变较小类的E值
    int k;
    for (k = i; node[k].link; k = node[k].link)
        node[k].E = j;
    node[k].E = j; //链尾结点
    //在链表j的首结点之后插入链表i, 并修改新链表的大小
    node[j].size += node[i].size;
    node[k].link = node[j].link;
    node[j].link = i;
}

int Find(int e)
{   //搜索包含元素i的类
    return node[e].E;
}

//把一个长整型数num转换为一个r进制数输出
void Transform(long num, int r) 
{
	Stack<int> a;  //利用栈a存储转换后得到的每一位数字
	while (num != 0) {  //由低到高求出r进制数的每一位并入栈
		int k = num % r;
		a.Push(k);
		num/=r;
	}
	while(!a.IsEmpty()) //由高到低输出r进制数的每一位
		cout << a.Pop();
	cout << endl;
}
#include <iostream.h>
#include "stack.h"
#include "position.h"

//全局变量
int **maze, m;
Stack<Position> *path;  //指向栈的指针

bool InputMaze()
{
    cout << "Enter maze size" << endl;
    cin >> m;
    Make2DArray(maze, m+2, m+2);
    cout << "Enter maze in row major order" << endl;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=m; j++) cin >> maze[i][j];
    return true;
}

//查找从 (1,1)到(m,m)的路径：成功时返回 true, 否则返回false
bool FindPath()  
{   
    path = new Stack<Position>(m * m - 1);

    //初始偏移量
    Position offset[4];
    offset[0].row = 0; offset[0].col = 1; 	//右
    offset[1].row = 1; offset[1].col = 0; 	//下
    offset[2].row = 0; offset[2].col = -1; 	//左
    offset[3].row = -1; offset[3].col = 0; 	//上
   
    //初始四周墙
    for (int i = 0; i <= m+1; i++) {
        maze[0][i] = maze[m+1][i] = 1; 	//上下
        maze[i][0] = maze[i][m+1] = 1; 	//左右
    }

    Position here;
    here.row = 1;
    here.col = 1;
    maze[1][1] = 1; //避免回到入口
    int option = 0; //下次移动
    int LastOption = 3;
    
    //查找一条路径
    while (here.row != m || here.col != m) {	//不存在
        //找相邻单元
        int r, c;      
        while (option <= LastOption) {
            r = here.row + offset[option].row;
            c = here.col + offset[option].col;
            if (maze[r][c] == 0) break;
            option++; //下一选择
    }

    //找到相邻单元?
    if (option <= LastOption) {    //进到maze[r][c]
        path->Push(here);
        here.row = r; here.col = c;
        maze[r][c] = 1;        //设为 1避免再次访问
        option = 0;
    }
    else {      //路径没有找到, 则回溯
        if (path->IsEmpty()) return false;
        Position next;
        path->TopandPop(next);
        if (next.row == here.row)
            option = 2 + next.col - here.col;
        else option = 3 + next.row - here.row;
        here = next;
    }
    }

    return true;  //到了出口
}


#include "stack.h"

const int MaxLength = 100; 		//最大表达式长度

void PrintMatchedPairs(char *expr)	//括号匹配算法
{ 
    Stack<int> s(MaxLength);
    int j, length = strlen(expr);

    //扫描表达式中的(和)
    for (int i = 1; i <= length; i++) {
        if (expr[i - 1] == '(') s.Push(i);
        else if (expr[i - 1] == ')')
            try { s.TopandPop(j);  //匹配
                cout << j << ' ' << i << endl; }
            catch (OutOfBounds)
            {   cout << "No match for right parenthesis"
                     << " at " << i << endl; }
    }
    ...
    //栈非空则不匹配
    while (!s.IsEmpty()) {
        s.TopandPop(j);
        cout << "No match for left parenthesis at " << j << endl;
    }
}
int farmer(int location) 
{
    return (0 !＝ (location & 0x08));
}

int wolf(int location) 
{
    return (0 !＝ (location & 0x04));
}

int cabbage(int location) 
{
    return (0 !＝ (location & 0x02));
}

int goat(int location) 
{
    return (0 !＝(location & 0x01));
}

int safe(int location)	//若状态安全则返回1
{
    if ((goat(location) == cabbage(location))
                      &&(goat(location) != farmer(location)))
        return (0); 		//羊吃白菜
    if ((goat(location) == wolf(location))
                      && (goat(location) != farmer(location)))  
        return (0); 		//狼吃羊
    return (1);				//其他状态是安全的
}
void farmerProblem()
{
    int movers, i,location,  newlocation;
    int route[16];        //记录已考虑的状态路径
    Queue moveTo;	
    moveto.MakeEmpty();		
    moveTo.EnQueue(0x00);
    for (i = 0; i < 16; i++)    route[i] = -1;
    route[0] = 0;
    while (!moveTo.isEmpty() && (route[15] == -1)) {
        location = moveTo.GetFront(); //得到现在的状态
        moveTo.DeQueue();
        for (movers = 1; movers <= 8;movers << 1) {
            //农夫总是在移动, 随农夫移动的也只能是在农夫同侧的东西 
            if ((0! = (location & 0x08)) == (0!=(location & movers))) {
                newlocation = location^(0x08|movers);
                if (safe(newlocation) && (route[newlocation] == -1)) {
                    route[newlocation]=location;     
                    moveTo.EnQueue(newlocation);
                }
            }
         } 
    }
    if (route[15] != -1) {		//打印出路径
        cout << "The reverse path is " << endl;
        for (location = 15; location >= 0; location = route[location]) {
            cout << "The location is" << location << endl;
            if (location == 0)  exit(0); 
        }  
    }
    else  printf("No solution.\n");
}
void proc_1(Stack S)   {  
    int i, n, A[255];
    n＝0;
    while (! EmptyStack(S))  {
        n++; Pop(&S, &A[n]);
     }
     for (i = 1; i <= n; i++)
         Push(&S, A[i]);
}
void proc_2(Stack S, int e)  {
    Stack T; int d;
    InitStack(&T);
    while (!EmptyStack(S))   {  
        Pop(&S, &d);
        if (d != e) Push(&T, d);
    }
    while(!EmptyStack(T))    {  
        Pop(&T, &d);
        Push(&S, d);
    }
}
void proc_3(Queue *Q)   {  
    Stack S; int d;
    InitStack(&S);
    while (!EmptyQueue(*Q))  {
        DeleteQueue(Q, &d);
        Push(&S, d);
    }
    while(!EmptyStack(S))    {  
        Pop(&S, &d);
        EnterQueue(Q, d);
    }
}
int sum_list(struct Lnode *l)
{
    if (l == NULL)
        return 0;
    return l->data + sum_list(l->next);
}
void fib(int n)
{
    int prev, now, next, j;
    if (n <= 1) return(n);
    else  {
        prev = 0;
        now = 1;
        for (j = 2; j <= n; j++)  {
            next = prev + now;
            prev = now;
            now = next;
        }
        return(next);
    }
}
print (int n) 
{    
     int i;
     if (n != 0)  {
         print(n-1);
         for (i = 1; i <= n; i++)
	         printf("%d", n);
	     printf("\n");
     }
}
int test1()
{
    int a = 3;
    test1();		//递归, 非尾递归 
    //返回后继续处理 
    a = a + 4;
    return a;
}

int test2()
{
    int q = 4;
    q = q + 5;
    return q + test1();	//非尾递归, 仍然有加法要做
}

int test3()
{
    int b = 5;
    b = b + 2;
    return test1();	//尾递归
}

int test4()
{
    test3();	//不在尾位置
    test3();	//不在尾位置
    return test3();	//在尾位置
}
void Hanoi(int n, string startpeg, string middlepeg, string endpeg)
{ 
    if(n == 1) //终止条件：移动一个盘子
        cout << "move" << startpeg << "to" << endpeg << endl;
    else {
        Hanoi(n-1, startpeg, endpeg, middlepeg); //将n-1个盘子移到middlepeg栓, 将底盘移//到endpeg栓
        cout << "move" << startpeg << "to" << endpeg << endl;
        Hanoi(n-1, middlepeg, startpeg, endpeg); //然后再将n-1个盘子从middlepeg栓移至
                                                 //endpeg栓
    }    
}
void findpath(int row, int col)
{
    int direct, next_row, next_col, k, l;
    direct = 0;
    while (direct < 4)
    {
        next_row = row + move[direct].vert;
        next_col = col + move[direct].horiz;
        if(maze[next_row][next_col] == 0)  {
            maze[next_row][next_col] = 2;
            if(next_row == MAX_ROW && next_col == MAX_COL)
                print_ans();
            else
                findpath(next_row, next_col);
            maze[next_row][next_col] = 0;
        }
        direct++;
    }
}
void place(int k)
{
    int i = 1;
    while (i < MAXQUEEN)
    {
        if (!attack(k, i))  {
            queen[k] = j;
            if (k == MAXQUEEN - 1)  {
                for (j = 1; j < MAXQUEEN; j++)
                    cout << j << queen[j];
                cout << endl;
            }
            else
                place(k+1);
        }
        i++;
    }
}

int attack(int k, int i)
{
    int j, m, atk;
    atk = 0;
    j = 1;
    while ((atk == 0) && (j < k))  {
        m = queen[j];
        atk = (m == i) || (abs(m-i) == abs(j-k));
        j++;
    }
    return(atk);
}
int Fact(int n)
{ 
    int i, fac;
    fac = 1; //将变量fac初始化为Fact(0)的值
    for (i = 1; i <= n; ++i) fac = i * fac; //根据递推关系进行递推
    return(fac);
}
#define MAXSIZE 20
typedef int listarr[MAXSIZE];
//将数组段list[left..right]中的元素按中点优先的顺序输出
void listorder(listarr list, int left, int right)
{   
    int mid;
    if (left <= right) //数组段不为空
    {
        mid = (left+right)/2; //取中点元素的值并输出
        printf("%4d", list[mid]);
        listorder(list, left, mid-1); //将中点左部的所有元素按中点优先的顺序输出
        listorder(list, mid+1, right);//将中点右部的所有元素按中点优先的顺序输出
    }
}
int StrConcat1(String s1, String s2, &String s)
{ 
    int i=0, j, len1, len2;
    len1 = s1.strLength(); len2 = s2.strLength()
    if (len1 + len2 > MAXSIZE ?1)  return  0 ; //s长度不够
    j = 0;
    while (s1.buffer[j] != '\0')  { s.buffer[i] = s1.buffer[j]; i++; j++; }
    j = 0;
    while (s2.buffer[j] != '\0')  { s.buffer[i] = s2.buffer[j]; i++; j++; }
    s.buffer[i]='\0';   //添加结束符
    return 1;
}
//用t返回串s中第个i字符开始的长度为len的子串1<=i<=串长
int StrSub (String &t, String s, int i, int len)
{
    int slen;
    slen = s.strLength();
    if (i<1 || i>slen || len<0 || len>slen-i+1)  { cerr << ＂参数不对＂ << endl;
        return 0;
    }
    for(j=0; j<len; j++)
        t.buffer[j] = s.buffer[i+j-1];
    t.buffer[j] = '\0'; 
    return 1;
}
int StrComp(String s1, String s2)
{
    int i = 0;
    while (s1.buffer[i] == s2[i].buffer && s1.buffer[i] != '\0') i++;
    return (s1.buffer [i]-s2.buffer [i]);
}
int StrIndex_BF　(String s, String t) //从串s的第一个字符开始找首次与串t相等的子串
{
    int i = 1,j = 1;
    while (I <= s.buffer[0] && j <= t.buffer [0])	//都没遇到结束符
        if (s.buffer[i] == t.buffer[j])
        { i++; j++; }								//继续
        else 
        { i = i-j+2; j = 1; }						//回溯
    if (j > t.buffer [0])  return (i - t.buffer[0]);	//匹配成功, 返回存储位置
    else  return –1;
}
//从串s的第pos个字符开始找首次与串t相等的子串
int StrIndex_KMP(char *s,char *t,int pos)
{  
    int i=pos, j=1, slen, tlen;
    while (i <= s[0] && j <= t[0])		//都没遇到结束符
        if (j == 0|| s[i] == t[j]) { i++; j++; }
        else  j = next(j);		//回溯
    if (j > t[0])  return  i - t[0];	//匹配成功, 返回存储位置
    else  return  –1;
}
//求模式t的next值并存入next数组中 
void GetNext(char *t,int next[])
{  
    int i=1,j=0;
    next[1]=0;
    while (i < t[0])
    {   while (j > 0 && t[i] != t[j])  j = next[j];
        i++;  j++; 
        if (t[i] == t[j])  next[i] = next[j]; 
        else  next[i] = j;
    }
}
void bmInitocc()
{
    char a;
    int j;
    for (a = 0; a < alphabetsize; a++) occ[a] = -1;
    for (j=0; j<m; j++)  {
        a = p[j];
        occ[a] = j;
    }
}
void bmPreprocess1()
{
    int i = m, j = m + 1;
    f[i] = j;
    while (i > 0){
        while (j <= m && p[i-1] !=p[j-1])  {
            if (s[j] == 0) s[j] = j-i;
            j = f[j];
        }
        i--;
        j--;
        f[i] = j;
    }
}
void bmPreprocess2()
{
    int i, j;
    j=f[1];
    for (i=1; i<=m; i++){
        if (s[i]==0) s[i]=j;
        if (i==j) j=f[j];
    }
}
int f[m+1], s[m+1];
void bmPreprocess()
{
    bmInitocc();
    bmPreprocess1();
    bmPreprocess2();
}
void bmSearch()
{
    int i=1, j;
    while (i <= n-m+1){
        j = m-1;
        while (j >= 1 && p[j] == t[i+j]) j--;
        if (j < 1)  {
            report(i);
            i+=s[1];
        }
        else i+=max(s[j+1], j-occ[t[i+j]]);
    }
}
//s: 读入字符串
//Words：分词结果表 
//countTable：基本词汇表, 采用散列表存储
ParseChinese(string s, List  &Words, HashTable countTable)
{
    int length = s.Length(); 
    String temp; temp.MakeEmpty();
    for (int i=0; i<s.Length;)  {
        temp = s.Substring(i, 1);
        if (countTable.GetCount(temp)>1)  { //不只一个子串
            int j = 2;
            for (; i+j < s.Length+1 && countTable.GetCount(s.Substring(i, j)) > 0; j++)
            {}
            temp = s.Substring(i, j-1);
            i = i + j - 2;
        }
        i++;
        words.Insert(temp);	//一个分词
    }
}
void Select(HTNode *HT, int k, int &s1, int &s2)
{
    int i;  s1, s2 = 1;
    T min1, min2 = HT[1].weight;
    for (i = 2; i <= k; i++) {
         if (HT[i].parent == 0 && i != s1 && i != s2)
             if (HT[i].weight<min1) {
                 s2 = s1; min2 = min1;
                 s1 = i; min1 = HT[i].weight; 
             }
             else if(HT[i].weight < min2)  { s2 = i; min2 = HT[i].weight; }
    }
}

//w存放n个字符的权值(均大于0), 构造赫夫曼树HT
template <class T>
void HuffmanTree(HTNode*&HT, T *w, int n)
{
    int c, f, i, m, s1, s2;
    HTNode *p;
    if (n <= 1) return;
    m = 2 * n - 1;
    HT = new HTNode[m+1]; //动态分配数组存储赫夫曼树 0号单元不用
    for(p = HT,i = 1;i <= n; ++i, ++p, ++w)
        p->weight = *w;
    for (i = n+1; i <= m;++i) {  //建赫夫曼树
        Select(HT, i-1, s1, s2);
        //选择parent为0且weight最小的两个结点, 其序号分别为s1和s2
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].left = s1;
        HT[i].right = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}
typedef char * *HuffmanCode; 		//动态分配数组存储赫夫曼编码表

//对赫夫曼树HT, 求出n个字符的赫夫曼编码HC
void HuffmanCoding(HTNode &HT, HuffmanCode &HC, int n)
{
    int c,f,i,start;
    char *cd;
    //从叶子到根逆向求每个字符的赫夫曼编码
    HC = new (char**)[n+1];	//分配n个字符编码的头指针向量
    cd = new (char *)[n];   	//分配求编码的工作空间
    cd[n-1] = '\0';        	//编码结束符位置
    for (i = 1; i <= n; i++) {   	//逐个字符求赫夫曼编码    
        start=n-1;
        for (c = i,f = HT[i].parent; f != 0; c = f, f = HT[f].parent)//从叶子到根逆向求
//编码写入操cd
            if(HT[f].left == c) cd[--start] = '0';
            else cd[--start] = '1';
        HC[i] = new(char*)[n-start];	//为第i个字符编码分配空间
        strcpy(HC[i], &cd[start]);	//从cd复制编码(串)到HC[i]
    }
    delete cd; //释放工作空间
}  
//m, n是矩阵A的行和列
void  saddle (int A[][],int m, int n)
{ 
    int i, j, min;
    for (i = 0; i < m; i++)  {			//按行处理
        min = A[i][0]; 
        for (j = 1; j < n; j++)
            if (A[i][j] < min ) min = A[i][j];	//找第i行最小值
                for (j = 0; j < n; j++)			//检测该行中的每一个最小值是否是鞍点
                    if (A[i][j] == min)  {
                        k=j;  p=0;
                        while (p < m && A[p][j] < min) p++;
                        if (p >= m) printf(＂%d,%d,%d\n＂, i, k, min);
                    }
    } 
}
//重载<<
//把*this 送至输出流
template <class T>
ostream& operator<<(ostream& out, const SparseMatrix<T>& x)
{   
    //输出矩阵的特征
    out << "rows = " << x.rows << " columns = " << x.cols << endl;
    out << "nonzero terms = " << x.terms << endl;
    //输出非零元素, 每行1个
    for (int i = 0; i < x.terms; i++)
        out << "data(" << x.data[i].row << ',' << x.data[i].col << ") = "
            << x.data[i].val << endl;
    return out;
}

//重载>>
//输入一个稀疏矩阵
template<class T>
istream& operator>>(istream& in, SparseMatrix<T>& x)
{  
    //输入矩阵的特征
    cout << "Enter number of rows, columns, and terms" << endl;
    in >> x.rows >> x.cols >> x.terms;
    if (x.terms > x.MaxTerms) throw NoMem();
    //输入矩阵元素
    for (int i = 0; i < x.terms; i++) {
        cout << "Enter row, column, and value of term " << (i + 1) << endl;
        in >> x.data[i].row >> x.data[i].col >> x.data[i].val;
    }
    return in;
}
