template <class Type> 
void RadixSort(staticlinklist<Type> &list, const int d,  const int radix) 
{
    int rear[radix],  front[radix];				
    for (int i = 1; i < list.CurrentSize; i++)
        list.Vector[i].setLink(i+1);
    list.Vector[n].setLink(0);			//静态链表初始化
    int current = 1;          			//链表扫描指针
    for (i = d-1; i >= 0; i--) {		//做 d 趟分配.收集
        for (int j = 0; j < radix; j++)  front[j] = 0; 
        while (current != 0) {			//逐个对象分配
            int k = list.Vector[current].getKey(key[i]);
            //取当前对象键的第 i 位 
            if (front[k] == 0) 		//原链表为空,对象链入
	            front[k] = current;		
	        else            			//原链表非空,链尾链入
	            list.Vector[rear[k]].setLink (current);
	        rear[k] = current;      	//修改链尾指针
	        current = list.Vector[current].getLink();   
        }
        j = 0;	          				//从0号队列开始收集		
        while (front[j] == 0) j++;		//空队列跳过
        current = front[j];        
        list.Vector[0].setLink(current);
        int last = rear[j];	      
        for (k = j+1; k < radix; k++)	//逐个队列链接
            if (front[k]) {
	            list.Vector[last].setLink(front[k]); 
	            last = rear[k];
            }
        list.Vector[last].setLink(0);
    }
}
