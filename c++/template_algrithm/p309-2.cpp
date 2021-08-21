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
