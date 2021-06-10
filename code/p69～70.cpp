//文件cqueue.h 
#ifndef CQueue_
#define CQueue_

template <class  DataType>
class CQueue {
private:
    DataType data[MaxQueueSize];     	//顺序队列数组
    int front;                      	//队首指示器
    int rear;                        	//队尾指示器
    int count;                        	//元素个数计数器
public:
    CQueue(void)                      	//构造函数
    { front = rear = 0; count = 0; }; 
    ~CQueue(void){};                  	//析构函数

    void EnQueue(const DataType& item);	//入队列
    DataType DelQueue(void);           	//出队列
    DataType GetFront(void)const;     	//取队首元素
    int NotEmpty(void)const           	//非空否
    { return count != 0; };
};

//把数据元素item插入队列作为当前的新队尾
void CQueue<class   DataType>::EnQueue(const DataType& item)   
{
    if (count > 0 && front == rear) {
        cout << "队列已满!" << endl;
        exit(0);
    }

    data[rear] = item;                 	//把元素item加在队尾
    rear = (rear + 1) % MaxQueueSize;  	//队尾指示器加1
    count++;                         	//计数器加1
}

//把队首元素出队列, 出队列元素由函数返回
DataType CQueue<class   DataType>::DelQueue(void)  
{
    if (count == 0) {
        cout << "队列已空!" << endl;
        exit(0);
    }

    DataType temp = data[front];          	//保存原队首元素
    front = (front + 1) % MaxQueueSize;    	//队首指示器加1
    count--;                               	//计数器减1
    return temp;                           	//返回原队首元素
}

DataType CQueue<class DataType>::GetFront(void)const 
//取队首元素并由函数返回
{  
    if(count == 0) {
        cout << "队列空!" << endl;
        exit(0);
    }
    return data[front];       //返回队首元素
}
#endif

