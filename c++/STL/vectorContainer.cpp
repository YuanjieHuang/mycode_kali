/*
vector 容器是 STL 中最常用的容器之一，它和 array 容器非常类似，都可以看做是对 C++ 普通数组的“升级版”。
不同之处在于，array 实现的是静态数组（容量固定的数组），而 vector 实现的是一个动态数组，
即可以进行元素的插入和删除，在此过程中，vector 会动态调整所占用的内存空间，整个过程无需人工干预。

创建方式：
std::vector<double> values;
std::vector<int> primes {2, 3, 5, 7, 11, 13, 17, 19};
std::vector<double> values(20);
std::vector<double> values(20, 1.0);

    int num=20;
    double value =1.0;
    std::vector<double> values(num, value);


    int array[]={1,2,3};
    std::vector<int>values(array, array+2);//values 将保存{1,2}
    std::vector<int>value1{1,2,3,4,5};
    std::vector<int>value2(std::begin(value1),std::begin(value1)+3);//value2保存{1,2,3}

*/

#include <iostream>
#include <vector>
#include <array>
using namespace std;

int vector_loop()
{
    vector<int> values{1,2,3,4,5};
    for (auto&& value : values)
        cout << value << " ";
    return 0;
}

int size_capacity()
{
    vector<int>value{ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
    cout << "value 容量是：" << value.capacity() << endl;
    cout << "value 大小是：" << value.size() << endl;
    printf("value首地址：%p\n", value.data());
    value.push_back(53);
    cout << "value 容量是(2)：" << value.capacity() << endl;
    cout << "value 大小是(2)：" << value.size() << endl;
    printf("value首地址： %p", value.data());
    return 0;
}

class testDemo
{
public:
    testDemo(int num):num(num){
        std::cout << "调用构造函数" << endl;
    }
    testDemo(const testDemo& other) :num(other.num) {
        std::cout << "调用拷贝构造函数" << endl;
    }
    testDemo(testDemo&& other) :num(other.num) {
        std::cout << "调用移动构造函数" << endl;
    }
private:
    int num;
};
void push_back_emplace_back()
{
    cout << "emplace_back:" << endl;
    std::vector<testDemo> demo1;
    demo1.emplace_back(2);  
    cout << "push_back:" << endl;
    std::vector<testDemo> demo2;
    demo2.push_back(2);
}

int vector_func()
{
    //初始化一个空vector容量
    vector<char>value;
    //向value容器中的尾部依次添加 S、T、L 字符
    value.push_back('S');
    value.push_back('T');
    value.push_back('L');
    //调用 size() 成员函数容器中的元素个数
    printf("元素个数为：%d\n", value.size());
    //使用迭代器遍历容器
    for (auto i = value.begin(); i < value.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    //向容器开头插入字符
    value.insert(value.begin(), 'C');
    cout << "首个元素为：" << value.at(0) << endl;
    vector_loop();
    return 0;
}

int vector_insert()
{
    std::vector<int> demo{1,2};
    //第一种格式用法
    demo.insert(demo.begin() + 1, 3);//{1,3,2}
    //第二种格式用法
    demo.insert(demo.end(), 2, 5);//{1,3,2,5,5}
    //第三种格式用法
    std::array<int,3>test{ 7,8,9 };
    demo.insert(demo.end(), test.begin(), test.end());//{1,3,2,5,5,7,8,9}
    //第四种格式用法
    demo.insert(demo.end(), { 10,11 });//{1,3,2,5,5,7,8,9,10,11}
    for (int i = 0; i < demo.size(); i++) {
        cout << demo[i] << " ";
    }
    return 0;
}

int vect_empalce()
{
    std::vector<int> demo1{1,2};
    //emplace() 每次只能插入一个 int 类型元素
    demo1.emplace(demo1.begin(), 3);
    for (int i = 0; i < demo1.size(); i++) {
        cout << demo1[i] << " ";
    }
    return 0;
}
/*
无论是向现有 vector 容器中访问元素、添加元素还是插入元素，都只能借助 vector 模板类提供的成员函数，
但删除 vector 容器的元素例外，完成此操作除了可以借助本身提供的成员函数，还可以借助一些全局函数。
*/

int vect_erase()
{
    vector<int>demo{ 1,2,3,4,5 };
    auto iter = demo.erase(demo.begin() + 1);//删除元素 2
    //输出 dmeo 容器新的size
    cout << "size is :" << demo.size() << endl;
    //输出 demo 容器新的容量
    cout << "capacity is :" << demo.capacity() << endl;
    for (int i = 0; i < demo.size(); i++) {
        cout << demo[i] << " ";
    }
    //iter迭代器指向元素 3
    cout << endl << *iter << endl;
    return 0;
}

int extern_swap()
{
    vector<int>demo{ 1,2,3,4,5 };
    //交换要删除元素和最后一个元素的位置
    swap(*(std::begin(demo)+1),*(std::end(demo)-1));//等同于 swap(demo[1],demo[4])
   
    //交换位置后的demo容器
    for (int i = 0; i < demo.size(); i++) {
        cout << demo[i] << " ";
    }
    demo.pop_back();
    cout << endl << "size is :" << demo.size() << endl;
    cout << "capacity is :" << demo.capacity() << endl;
    //输出demo 容器中剩余的元素
    for (int i = 0; i < demo.size(); i++) {
        cout << demo[i] << " ";
    }
    return 0;
}
#if 0
int main()
{
    push_back_emplace_back();
    cout<<endl;
    extern_swap();
}
#endif
int main()
{
    vector<int>myvector;
    //手动为 myvector 扩容
    myvector.reserve(1000);
    cout << "1、当前 myvector 拥有 " << myvector.size() << " 个元素，容量为 " << myvector.capacity() << endl;
    //利用 myvector 容器存储 10 个元素
    for (int i = 1; i <= 10; i++) {
        myvector.push_back(i);
    }
    //将 myvector 容量缩减至 10
    vector<int>(myvector).swap(myvector);
    cout << "2、当前 myvector 拥有 " << myvector.size() << " 个元素，容量为 " << myvector.capacity() << endl;
    vector<int>().swap(myvector);
    cout << "2、当前 myvector 拥有 " << myvector.size() << " 个元素，容量为 " << myvector.capacity() << endl;
    return 0;
}