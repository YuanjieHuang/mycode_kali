    #include <iostream>
    #include <iterator>
    #include <list>
    #include <vector>
    #include <algorithm>
    using namespace std;
    int create_reverse_iterator()
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

    int reverse_iterator_test()
    {
        std::list<int> values{ 1,2,3,4,5 };
        std::list<int>::iterator ls;
        for(auto i=values.begin(); i!=values.end();i++ )
        {
            cout << *i<< " ";
        }
        cout<<endl;
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

    int istream_iterator_test() {
    //用于接收输入流中的数据
    double value1, value2;
    cout << "请输入 2 个小数: ";
    //创建表示结束的输入流迭代器
    istream_iterator<double> eos;
    //创建一个可逐个读取输入流中数据的迭代器，同时这里会让用户输入数据
    istream_iterator<double> iit(cin);
    //判断输入流中是否有数据
    if (iit != eos) {
        //读取一个元素，并赋值给 value1
        value1 = *iit;
    }
    //如果输入流中此时没有数据，则用户要输入一个；反之，如果流中有数据，iit 迭代器后移一位，做读取下一个元素做准备
    iit++;
    if (iit != eos) {
        //读取第二个元素，赋值给 value2
        value2 = *iit;
    }
    //输出读取到的 2 个元素
    cout << "value1 = " << value1 << endl;
    cout << "value2 = " << value2 << endl;
    return 0;
}

int ostream_iterator_test() {
    //创建一个输出流迭代器
    ostream_iterator<string> out_it(cout);
    //向 cout 输出流写入 string 字符串
    *out_it = "http://c.biancheng.net/stl/\t";
    // ++out_it;
    out_it = "append\n";
    cout << endl;
    // //创建一个输出流迭代器，设置分隔符 ,
    // ostream_iterator<int> out_it1(cout, ",");
    // //向 cout 输出流依次写入 1、2、3
    // *out_it1 = 1;
    // *out_it1 = 2;
    // *out_it1 = 3;
    return 0;
}

int ostream_iterator_copy() {
    //创建一个 vector 容器
    vector<int> myvector;
    //初始化 myvector 容器
    for (int i = 1; i < 10; ++i) {
        myvector.push_back(i);
    }
    //创建输出流迭代器
    std::ostream_iterator<int> out_it(std::cout, ", ");
    //将 myvector 容器中存储的元素写入到 cout 输出流中
    std::copy(myvector.begin(), myvector.end(), out_it);
    return 0;
}

int main()
{
    istream_iterator_test();
    ostream_iterator_test();
    return 0;
}