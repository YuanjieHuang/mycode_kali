class IntArray{
    int low;  
    int high;
    int *storage;

public:
    //构造函数根据low和high为数组分配空间
    IntArray(int lh, int rh):low(lh), high(rh)
    {storage = new int [high - low + 1]; }	

    //设置数组元素的值
    //返回值为true表示操作正常，返回值为false表示下标越界
    bool insert(int index, int value);

    //取数组元素的值
    //返回值为true表示操作正常，为false表示下标越界
    bool fatch(int index, int &value);

    //析构函数
    ~IntArray() {delete [] storage; }
};

