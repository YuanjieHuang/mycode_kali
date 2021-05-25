/*
    //拷贝普通数组，创建forward_list容器
    int a[] = { 1,2,3,4,5 };
    std::forward_list<int> values(a, a+5);
    //拷贝其它类型的容器，创建forward_list容器
    std::array<int, 5>arr{ 11,12,13,14,15 };
    std::forward_list<int>values(arr.begin()+2, arr.end());//拷贝arr容器中的{13,14,15}

*/
#include <iostream>
#include <forward_list>
using namespace std;
int flist_func()
{
    std::forward_list<int> values{1,2,3};
    values.emplace_front(4);//{4,1,2,3} 在容器头部生成一个元素。该函数和 push_front() 的功能相同，但效率更高。
    //在指定位置之后插入一个新元素，并返回一个指向新元素的迭代器。和 insert_after() 的功能相同，但效率更高。
    values.emplace_after(values.before_begin(), 5); //{5,4,1,2,3}  before_begin其指向容器中第一个元素之前的位置
    values.reverse();//{3,2,1,4,5}
    for (auto it = values.begin(); it != values.end(); ++it) {
        cout << *it << " ";
    }
    cout<<endl;
    return 0;
}

int flist_distance()
{
    std::forward_list<int> my_words{1,2,3,4,5,6};
    int count = std::distance(std::begin(my_words), std::end(my_words));
    cout << count;
    cout<<endl;
    return 0;
}

int flist_advance()
{
    std::forward_list<int> values{1,2,3,4,5,6,7};
    auto it = values.begin();
    advance(it, 3);//forward_list 容器迭代器的移动除了使用 ++ 运算符单步移动，还能使用 advance() 函数
    while (it!=values.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout<<endl;
    return 0;
}

int main()
{
    flist_func();
    flist_distance();
    flist_advance();
    return 0;
}