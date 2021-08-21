//二分查找的迭代算法 
template <class Type> 
int  SqSTable <Type>::BinarySearch(const Type & k) const
{	      
    int high = CurrentSize,　low = 1,　mid;		//步骤1:设置初始区间
    while (low <= high) {		       			//步骤2:表空测试
        mid = (low + high) / 2;		  		//步骤3:得到中点
        if (Element[mid].getKey() < k) 
            low = mid + 1;						//调整到右半区
        else if (Element[mid].getKey() > k) 
            high = mid - 1;        				//调整到左半区
        else return mid;   					//查找成功, 返回元素位置
    }	  
    return 0;									//查找失败
}
