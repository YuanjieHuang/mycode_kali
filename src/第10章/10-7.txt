class IntArray{
private:
    int low;  
    int high;
    int *storage;

public:
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
};

