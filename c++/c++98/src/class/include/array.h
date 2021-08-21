//文件名：array.h
//array库的接口
#ifndef _array_h
#define _array_h

//可指定下标范围的数组的存储
struct IntArray{
    int low;  
    int high;
    int *storage;
};

//根据low和high为数组分配空间。分配成功，返回值为true，否则返回值为false
bool initialize(IntArray &arr, int low, int high);

//设置数组元素的值
//返回值为true表示操作正常，返回值为false表示下标越界
bool insert(const IntArray &arr, int index, int value);

//取数组元素的值
//返回值为true表示操作正常，返回值为false表示下标越界
bool fatch(const IntArray &arr, int index, int &value);

//回收数组空间
void cleanup(const IntArray &arr);

//根据low和high为数组分配空间。分配成功，返回值为true，否则返回值为false
bool initialize(int lh, int rh);

//设置数组元素的值
//返回值为true表示操作正常，返回值为false表示下标越界
bool insert(int index, int value);

//取数组元素的值
//返回值为true表示操作正常，返回值为false表示下标越界
bool fatch(int index, int &value);

//回收数组空间
void cleanup();



#endif

