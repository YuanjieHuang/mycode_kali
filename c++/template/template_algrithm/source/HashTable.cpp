//求在散列表T[0..m-1]中第i次探查的散列地址hi, 0<=i<=m-1
//下面的h是散列函数, Increment是求增量序列的函数, 它依赖于解决冲突的方法
int Hash(KeyType k, int i)
{ 
    return(h(K)+Increment(i))%m; //Increment(i)相当于是di
}
//查找
int HashTable：：Find(const DataType &x)　const	
{
	int i = x.key % TableSize;
	int j = i;
	while (ht[j].info == Active && ht[j].data != x)　 {	//说明存在冲突
		j = (j + 1) % TableSize;		//用解决冲突方法继续查找
		if(j == i) return -TableSize;	//说明已遍历整个散列表未找到且表已满
	}
	
	if (ht[j].info == Active) 
		return j;		//找到, 返回正值
	else 
		return -j;	//未找到, 返回负值
}

int HashTable：：Insert(const DataType &x)
{
	int i = Find(x); 				//调用Find(x)

	if(i > 0) return 0;			//数据元素x已经存在
	else if(i != -TableSize)　{		//数据元素x不存在且散列表未满
	
		ht[-i].data = x;			//数据元素赋值
		ht[-i].info = Active;		//置活动标记
		currentSize++;			//当前表项个数加1
		return 1;					//返回插入成功状态
	}
	else return 0;				//返回插入失败状态
}
//删除
int HashTable：：Delete(const DataType &x)		
{
	int i = Find(x); 							//调用Find(x)

	if (i >= 0)　{
		ht[i].info = Deleted;					//置删除标记
		currentSize--;						//当前表项个数减1
		return 1;								//返回删除成功状态
	}
	else return 0;							//返回删除失败状态
}
