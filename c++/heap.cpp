#include<iostream>
#include<algorithm>
#include"Heap.h"
#include "SortTestHelper.h"

//将所有元素插入堆，再取出
template<typename T>
void heapSort1(T arr[],int n){

    MaxHeap<T> maxheap = MaxHeap<T>(n); 
    for(int i=0;i<n;i++)
        maxheap.insert(arr[i]);

    //从小到大排序
    for(int i=n-1;i>=0;i--)
        arr[i] = maxheap.extracMax();

}


// heapSort2, 借助我们的heapify过程创建堆
// 此时, 创建堆的过程时间复杂度为O(n), 将所有元素依次从堆中取出来, 实践复杂度为O(nlogn)
// 堆排序的总体时间复杂度依然是O(nlogn), 但是比上述heapSort1性能更优, 因为创建堆的性能更优
template<typename T>
void heapSort2(T arr[], int n){

    MaxHeap<T> maxheap = MaxHeap<T>(arr,n);
    for( int i = n-1 ; i >= 0 ; i-- )
        arr[i] = maxheap.extracMax();

}

int main(){
    
    int n = 10;
    
    
    // 测试1 一般性测试
    //cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
        
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr1, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr2, n);
    
    for(int i=0;i<n;i++)
        cout << arr1[i] << " ";
    cout << endl;
    
    for(int i=0;i<n;i++)
        cout << arr2[i] << " ";
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    cout <<endl;
}