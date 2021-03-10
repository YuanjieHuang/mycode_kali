    #include <iostream>
    #include <list>
    using namespace std;
    int main0()
    {
        std::list<int> values{1,2,3,4,5};
        //找到遍历的开头位置和结尾位置
        std::list<int>::iterator begin = --values.end();
        std::list<int>::iterator end = --values.begin();
        //开始遍历
        while (begin != end)
        {
            cout << *begin << " ";
            --begin;
        }
        return 0;
    }

    int main()
    {
        std::list<int> values{ 1,2,3,4,5 };
        //找到遍历的起点和终点，这里无需纠结定义反向迭代器的语法，后续会详细讲解
        std::reverse_iterator<std::list<int>::iterator> begin = values.rbegin();
        std::reverse_iterator<std::list<int>::iterator> end = values.rend();
        while (begin != end) {
            cout << *begin << " ";
            //注意，这里是 ++，因为反向迭代器内部互换了 ++ 和 -- 的含义
            ++begin;
        }
        return 0;
    }