//文件名：array.cpp
//array库的实现
#include "array.h"
#include <iostream>
using namespace std;

//根据low和high为数组分配空间。分配成功，返回值为true，否则返回值为false
bool initialize(IntArray &arr, int low, int high)
{  arr.low = low; 
   arr.high = high;
   arr.storage = new int [high - low + 1];
   if (arr.storage == NULL) return false; else return true;
}
　　
//设置数组元素的值
//返回值为true表示操作正常，返回值为false表示下标越界
bool insert(const IntArray &arr, int index, int value)
{  if (index < arr.low || index > arr.high) return false;
   arr.storage[index - arr.low] = value;
   return true;
}

//取数组元素的值
//返回值为true表示操作正常，返回值为false表示下标越界
bool fatch(const IntArray &arr, int index, int &value)
{  if (index < arr.low || index > arr.high) return false;
   value = arr.storage[index - arr.low] ;
   return true;
}

//回收数组空间
void cleanup(const IntArray &arr)
{    delete [] arr.storage; }


//根据low和high为数组分配空间。分配成功，返回值为true，否则返回值为false
bool IntArray::initialize(int lh, int rh)
{   low = lh;
    high = rh;
    storage = new int [high - low + 1];
    if (storage == NULL) return false; else return true;
}

//设置数组元素的值
//返回值为true表示操作正常，返回值为false表示下标越界
bool IntArray::insert(int index, int value)
{   if (index < low || index > high) return false;
    storage[index - low] = value;
    return true;
}

//取数组元素的值
//返回值为true表示操作正常，返回值为false表示下标越界
bool IntArray::fatch(int index, int &value)
{   if (index < low || index > high) return false;
    value = storage[index - low] ;
    return true;
}

//回收数组空间
void IntArray::cleanup()
{   delete [] storage; }