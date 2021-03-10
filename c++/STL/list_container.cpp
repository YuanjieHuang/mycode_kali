    #include <iostream>
    #include <list>
    #include <array>
    #include <forward_list>
    using namespace std;

int list_insert()
{
    std::list<int> values{ 1,2 };
    //第一种格式用法
    values.insert(values.begin() , 3);//{3,1,2}
    //第二种格式用法
    values.insert(values.end(), 2, 5);//{3,1,2,5,5}
    //第三种格式用法
    std::array<int, 3>test{ 7,8,9 };
    values.insert(values.end(), test.begin(), test.end());//{3,1,2,5,5,7,8,9}
    //第四种格式用法
    values.insert(values.end(), { 10,11 });//{3,1,2,5,5,7,8,9,10,11}
    for (auto p = values.begin(); p != values.end(); ++p)
    {
        cout << *p << " ";
    }
    return 0;
}

int list_splice()
{
    //创建并初始化 2 个 list 容器
    list<int> mylist1{ 1,2,3,4 }, mylist2{10,20,30};
    list<int>::iterator it = ++mylist1.begin(); //指向 mylist1 容器中的元素 2
    
    //调用第一种语法格式
    mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                    // mylist2:
                                    // it 迭代器仍然指向元素 2，只不过容器变为了 mylist1
        cout << "mylist1 包含 " << mylist1.size() << "个元素" << endl;
    //调用第二种语法格式，将 it 指向的元素 2 移动到 mylist2.begin() 位置处
    mylist2.splice(mylist2.begin(), mylist1, it);   // mylist1: 1 10 20 30 3 4
                                                    // mylist2: 2
                                                    // it 仍然指向元素 2
    
    //调用第三种语法格式，将 [mylist1.begin(),mylist1.end())范围内的元素移动到 mylist.begin() 位置处                  
    mylist2.splice(mylist2.begin(), mylist1, mylist1.begin(), mylist1.end());//mylist1:
                                                                                //mylist2:1 10 20 30 3 4 2
    
    cout << "mylist1 包含 " << mylist1.size() << "个元素" << endl;
    cout << "mylist2 包含 " << mylist2.size() << "个元素" << endl;
    //输出 mylist2 容器中存储的数据
    cout << "mylist2:";
    for (auto iter = mylist2.begin(); iter != mylist2.end(); ++iter) {
        cout << *iter << " ";
    }
    return 0;
}

int del_func()
{
    list<int>values{ 1,2,3,4 };
   
    //删除当前容器中首个元素
    values.pop_front();//{2,3,4}
   
    //删除当前容器最后一个元素
    values.pop_back();//{2,3}
   
    //清空容器，删除容器中所有的元素
    values.clear(); //{}
   
    for (auto begin = values.begin(); begin != values.end(); ++begin)
    {
        cout << *begin << " ";
    }
    return 0;
}

int list_erase()
{
    list<int>values{ 1,2,3,4,5 };
    //指向元素 1 的迭代器
    auto del = values.begin();
    //迭代器右移，改为指向元素 2
    ++del;
    values.erase(del); //{1,3,4,5}
    for (auto begin = values.begin(); begin != values.end(); ++begin)
    {
        cout << *begin << " ";
    }
    return 0;
}

int list_erase2()
{
    list<int>values{ 1,2,3,4,5 };
    //指定删除区域的左边界
    auto first = values.begin();
    ++first;//指向元素 2
    //指向删除区域的右边界
    auto last = values.end();
    --last;//指向元素 5
    //删除 2、3 和 4
    values.erase(first, last);
    for (auto begin = values.begin(); begin != values.end(); ++begin)
    {
        cout << *begin << " ";
    }
    return 0;
}

int list_remove()
{
    list<char>values{'a','b','c','d'};
    values.remove('c');
    for (auto begin = values.begin(); begin != values.end(); ++begin)
    {
        cout << *begin << " ";
    }
    return 0;
}

//二元谓词函数
bool demo(double first, double second)
{
    return (int(first) == int(second));
}
int list_unique()
{
    list<double> mylist{ 1,1.2,1.2,3,4,4.5,4.6 };
    //删除相邻重复的元素，仅保留一份
    mylist.unique();//{1, 1.2, 3, 4, 4.5, 4.6}
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << *it << ' ';
    cout << endl;
    //demo 为二元谓词函数，是我们自定义的去重规则
    mylist.unique(demo);
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        std::cout << *it << ' ';
    return 0;
}

int list_remove_if()
{
    std::list<int> mylist{ 15, 36, 7, 17, 20, 39, 4, 1 };
    //删除 mylist 容器中能够使 lamba 表达式成立的所有元素。
    mylist.remove_if([](int value) {return (value < 10); }); //{15 36 17 20 39}
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        std::cout << ' ' << *it;
    return 0;
}

int main()
{
    std::forward_list<int> values{1,2,3,4};
    auto it = values.begin();
    advance(it, 2);
    while (it!=values.end())
    {
        cout << *it << " ";
        ++it;
    }

    std::forward_list<int> my_words{1,2,3,4};
    int count = std::distance(std::begin(my_words), std::end(my_words));
    cout << "distance:"<< count<<endl;
    return 0;
}