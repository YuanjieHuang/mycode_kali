#ifndef HEAP_H_
#define HEAP_H_

#include<algorithm>
#include<cassert>
using namespace std;

template<typename Item>
class MaxHeap{
private:
    Item *data;    //数组
    int count;    //堆的大小
    int capacity;    //堆的容量

    void shiftUp(int k){
        while(k>1 && data[k/2]<data[k]){
            swap(data[k/2],data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k){
        while(2*k<=count){
            int j = 2*k;
            if(j+1<count && data[j+1]>data[j]) j++; //右孩子比左孩子，j移动
            if(data[k]>data[j]) break;
            swap(data[k],data[j]);
            k=j;
        }
    }
public:
    //构造函数 构建一个空堆
    MaxHeap(int capacity){

        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }

    //构造函数，通过给定数组实现最大堆 O(n)
    MaxHeap(Item arr[],int n){
        
        data = new Item[n+1];
        capacity = n;

        for(int i=0;i<n;i++)
            data[i+1] = arr[i];
        count = n;

        for(int i=count/2;i>=1;i--)
            shiftDown(i);
    }

    ~MaxHeap(){
        delete[] data;
    }

    //返回堆中的元素个数
    int size(){
        return count;
    }

    //判断是否为空
    bool isEmpty(){
        return count==0;
    }

    //向最大堆中插入元素
    void insert(Item item){
        assert(count+1<=capacity);
        data[count+1] = item;
        shiftUp(count+1);
        count++;
    }

    //从最大堆中取出堆顶元素
    Item extracMax(){
        assert(count > 0);
        Item ret = data[1];
        swap(data[1],data[count]);
        count--;
        shiftDown(1);
        return ret;
    }

};

#endif
