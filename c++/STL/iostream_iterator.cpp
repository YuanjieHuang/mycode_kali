
/*
    流迭代器也是一种迭代器适配器，不过和之前讲的迭代器适配器有所差别，它的操作对象不再是某个容器，而是流对象。
    即通过流迭代器，我们可以读取指定流对象中的数据，也可以将数据写入到流对象中。
    std::istream_iterator<double> iit(std::cin);
    这里创建了一个可从标准输入流 cin 读取数据的输入流迭代器。
    值得注意的一点是，通过此方式创建的输入流迭代器，其调用的构造函数中，会自行尝试去指定流中读取一个指定类型的元素。
*/
    #include <iostream>
    #include <iterator>
    #include <list>
    #include <vector>
    #include <algorithm>
    #include <string>
    using namespace std;
    int test_istream_iterator() {
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

    /*
    constructor:
        std::ostream_iterator<int> out_it(std::cout);
        std::ostream_iterator<int> out_it(std::cout，",");
        std::ostream_iterator<int> out_it1(out_it);
    */

   int test_ostream_iterator() {
    //创建一个输出流迭代器
    ostream_iterator<string> out_it(cout);
    //向 cout 输出流写入 string 字符串
    *out_it = "http://c.biancheng.net/stl/";
    cout << endl;
    //创建一个输出流迭代器，设置分隔符 ,
    ostream_iterator<int> out_it1(cout, ",");
    //向 cout 输出流依次写入 1、2、3
    *out_it1 = 1;
    *out_it1 = 2;
    *out_it1 = 3;
    cout<<endl;
    return 0;
}

int ostream_iteratro_copy() {
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

int test(void)
{
    vector<int> vecs;
    list<int> ls, ls1, ls2, ls3;
 
    ostream_iterator<int> outite(cout, " ");
    istream_iterator<int> inite(cin), eof;
    while(inite != eof)
    {
        vecs.push_back(*inite++);
    }
    copy(vecs.cbegin(), vecs.cend(), outite);
    cout << endl;
 
    back_inserter(ls) = 1;
    back_inserter(ls) = 2;
 
    front_inserter(ls) = 3;
    front_inserter(ls) = 4;
 
    inserter(ls, ls.begin()) = 5;
    inserter(ls, ls.end()) = 6;
 
    back_insert_iterator<list<int> > backIter(ls);
    *backIter = 7;
    *backIter = 8;
 
    front_insert_iterator<list<int> > frontIter(ls);
    *frontIter = 9;
    *frontIter = 10;
 
    insert_iterator<list<int> > insertIter(ls, ls.begin());
    *insertIter = 11;
    *insertIter = 12;
 
    copy(ls.cbegin(), ls.cend(), outite);
    cout << endl;
 
    copy(ls.cbegin(), ls.cend(), front_inserter(ls1));
    copy(ls1.cbegin(), ls1.cend(), outite);
    cout << endl;
 
    copy(ls.cbegin(), ls.cend(), back_inserter(ls2));
    copy(ls2.cbegin(), ls2.cend(), outite);
    cout << endl;
 
    copy(ls.cbegin(), ls.cend(), inserter(ls3, ls3.begin()));
    copy(ls3.cbegin(), ls3.cend(), outite);
    cout << endl;
 
    return 0;
}

int main()
{
    istream_iterator<string> is(cin);
    istream_iterator<string> eof;
 
    vector<string> text;
    copy(is, eof, back_inserter(text));
 
    sort(text.begin(), text.end());
 
    ostream_iterator<string> os(cout, " ");
    copy(text.begin(), text.end(), os);
 
    return 0;
}

// int main()
// {
//     test_istream_iterator();
//     test_ostream_iterator();
//     ostream_iteratro_copy();
//     test();
//     return 0;
// }