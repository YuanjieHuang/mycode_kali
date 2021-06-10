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
