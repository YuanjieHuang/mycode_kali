const int MaxPQSize  = 50;
class PQueue {
private:
    int count;
	DataType pqlist[MaxPQSize];

public:
	PQueue (void) : count(0) {};
            
	//优先队列的更新操作
	void  PQInsert(const DataType& item);
	DataType PQDelete(void);
	void ClearPQ(void);
        
	//优先队列的引用操作
	int PQEmpty(void) const;
	int PQFull(void) const;
	int PQLength(void) const;
};

//优先队列的入队
void PQueue::PQInsert (const DataType& item)
{
	if (count == MaxPQSize) {  //队满？
		cerr << "Priority queue overflow!" << endl;
		exit(1);
    }
    //非满时入队
    pqlist[count] = item;
    count++;
}
                    
//优先队列的出队
DataType PQueue::PQDelete(void)
{
    DataType min;
    int i, minindex = 0;

    if (count > 0) {
        //查找最小元素
        min = pqlist[0];    
        
        for (i = 1; i < count; i++)
            if (pqlist[i] < min) {   //记录新的当前最小元素及位置
                min = pqlist[i];
                minindex = i;
            }
        //出队
        pqlist[minindex] = pqlist[count-1];
        count--;
    }
    else {  //队空则退出
        cerr << "Deleting from an empty priority queue!" << endl;
        exit(1);
    }
    //返回最小值 
    return min;
}
                    
//优先队列判空
int PQueue::PQEmpty(void) const
{
    return count == 0;
}

//优先队列判满
int PQueue::PQFull(void) const
{
    return count == MaxPQSize; 
}
    
//优先队列置空
void PQueue::ClearPQ(void)
{
    count = 0;
}

