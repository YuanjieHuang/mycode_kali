#include <iostream>
#include <memory>
#include <climits>
using namespace std;
int main()
{
    std::shared_ptr<int> p7(new int[10], [](int* p) {delete[]p; });
    //构建 2 个智能指针
    std::shared_ptr<int> p1(new int(10));
    std::shared_ptr<int> p2(p1);
    //输出 p2 指向的数据
    cout << *p1.get() << endl;
    cout << *p2 << endl;
    p1.reset();//引用计数减 1,p1为空指针
    if (p1) {
        cout << "p1 不为空" << endl;
    }
    else {
        cout << "p1 为空" << endl;
    }
    //以上操作，并不会影响 p2
    cout << *p2 << endl;
    //判断当前和 p2 同指向的智能指针有多少个
    cout << p2.use_count() << endl;
    cout << endl;

    std::shared_ptr<int> sp1(new int(10));
    std::shared_ptr<int> sp2(sp1);
    std::weak_ptr<int> wp(sp2);
    //输出和 wp 同指向的 shared_ptr 类型指针的数量
    cout << wp.use_count() << endl;
    //释放 sp2
    sp2.reset();
    cout << wp.use_count() << endl;
    //借助 lock() 函数，返回一个和 wp 同指向的 shared_ptr 类型指针，获取其存储的数据
    cout << *(wp.lock()) << endl;
    return 0;
}