#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

#define SHOW_CONTAINER_DATA cout << "myvec:" << endl;\
    for (auto ch : myvec) {\
        cout << ch << " ";\
    }\
    cout << endl << "othvec:" << endl;\
    for (auto ch : othvec) {\
        cout << ch << " ";\
    }\
    cout<<endl<<"=================="<<endl<<endl
int normal_copy()
{
        //创建并初始化一个 vector 容器
    vector<string> myvec{ "STL","Python","Java" };
    //再次创建一个 vector 容器，利用 myvec 为其初始化
    vector<string>othvec(myvec.begin(), myvec.end());
    SHOW_CONTAINER_DATA;
    return 0;
}

int move_iterator_test()
{
    //创建并初始化一个 vector 容器
    vector<string> myvec{ "STL","Python","Java" };
    //再次创建一个 vector 容器，利用 myvec 为其初始化
    vector<string>othvec(make_move_iterator(myvec.begin()), make_move_iterator(myvec.end()));
    SHOW_CONTAINER_DATA;
    return 0;
}

int move_iterator_base()
{
    typedef std::vector<std::string>::iterator Iter;
    //创建并初始化一个 vector 容器
    vector<std::string> myvec{ "STL","Java","Python" };
    //创建 2 个移动迭代器
    std::move_iterator<Iter>begin = make_move_iterator(myvec.begin());
    std::move_iterator<Iter>end = make_move_iterator(myvec.end());
    //以复制的方式初始化 othvec 容器
    vector <std::string> othvec(begin.base(), end.base());
    SHOW_CONTAINER_DATA;
    return 0;
}
int main()
{
    normal_copy();
    move_iterator_test();
    move_iterator_base();
    return 0;
}