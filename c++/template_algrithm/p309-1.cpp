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

