//文件名：10-8.h
//将成员函数定义为内联函数
#ifndef_IntArray
#define_IntArray

class IntArray{
private:
    int low;  
    int high;
    int *storage;

public:
    //根据low和high为数组分配空间。分配成功，返回值为true，否则返回值为false
    bool initialize(int lh, int rh);
    {  low = lh;
       high = rh;
       storage = new int [high - low + 1];
       if (storage == NULL) return false; else return true;
    }
    //设置数组元素的值
    //返回值为true表示操作正常，返回值为false表示下标越界
    bool insert(int index, int value);
    {  if (index < low || index > high) return false;
       storage[index - low] = value;
       return true;
    }

    //取数组元素的值
    //返回值为true表示操作正常，返回值为false表示下标越界
    bool fatch(int index, int &value);
    {  if (index < low || index > high) return false;
       value = storage[index - low] ;
       return true;
    }

    //回收数组空间
    void cleanup()
    {  delete [] storage;   }
};
#endif

