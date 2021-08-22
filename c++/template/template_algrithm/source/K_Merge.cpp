typedef  int LoserTree[k]; //败者树是完全二叉树且不含叶子, 可采用顺序存储结构

typedef  struct {
	KeyType  key;
}ExNode,External[k];    //外结点,只存放待归并记录的键

//k路归并处理程序
//利用败者树ls将编号从0到k-1的k个输入归并段中的记录归并到输出归并段
//b[0]到b[k-1]为k个叶结点, 分别存放k个输入归并段中当前记录的键
void  K_Merge(LoserTree *ls,External *b)		
{	
	
	//分别从k个输入归并段读入该段当前第一个记录的键到外结点
	for (i = 0; i < k; i++)  input(b[i].key); 
	CreateLoserTree(ls); 	//建败者树ls, 选得最小键为b[0].key
	While (b[ls[0]].key != MAXKEY)
	{	q = ls[0]; 			//q指示当前最小键所在归并段
		output(q);	//将编号为q的归并段中当前(键为b[q].key)的记录写至输出归并段
		input(b[q].key); 	//从编号为q的输入归并段中读入下一个记录的键
		Adjust(ls,q); 	//调整败者树, 选择新的最小键
	}
	output(ls[0]); 		//将含最大键MAXKEY的记录写至输出归并段
}

//选得最小键记录后, 从叶到根调整败者树, 选下一个最小键
//沿从叶结点b[s]到根结点ls[0]的路径调整败者树
void  Adjust(LoserTree *ls,int s) 
{	
	t = (s+k)/2;   //ls[t]是b[s]的父结点
	while (t > 0) {
		if (b[s].key > b[ls[t]].key)   s<-->ls[t]; {  
			int temp = s; s = ls[t]; ls[t] = temp; //s指示新的胜者
		{	
		t = t/2;
	}
	ls[0] = s;
}
//建立败者树, b[0]到b[k-1]为完全二叉树ls的叶结点, 存有k个键
//将ls调整为败者树
void   CreateLoserTree(LoserTree *ls) 
{
	b[k].key = MINKEY; 					//设MINKEY为键可能的最小值
	for(i = 0; i < k; i++)   ls[i] = k;		//设置ls中“败者”的初值
	for(i = k-1; k > 0; i--)  Adjust(ls,i);	//依次从b[k-1],b[k-2],…,b[0]出发调整败者
}
