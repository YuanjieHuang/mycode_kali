    #include <iostream>
    #include <map> //使用 map 容器，必须引入该头文件
    #include <string>
    #include <utility>
    using namespace std;
    /*
    pair 类模板定义在<utility>头文件中

    #1) 默认构造函数，即创建空的 pair 对象
    pair();
    #2) 直接使用 2 个元素初始化成 pair 对象
    pair (const first_type& a, const second_type& b);
    #3) 拷贝（复制）构造函数，即借助另一个 pair 对象，创建新的 pair 对象
    template<class U, class V> pair (const pair<U,V>& pr);

    #4) 移动构造函数
    template<class U, class V> pair (pair<U,V>&& pr);
    #5) 使用右值引用参数，创建 pair 对象
    template<class U, class V> pair (U&& a, V&& b);
    
    */

int pair_structor() {
    // 调用构造函数 1，也就是默认构造函数
    pair <string, double> pair1;
    // 调用第 2 种构造函数
    pair <string, string> pair2("STL教程","http://c.biancheng.net/stl/");  
    // 调用拷贝构造函数
    pair <string, string> pair3(pair2);
    //调用移动构造函数
    pair <string, string> pair4(make_pair("C++教程", "http://c.biancheng.net/cplus/"));
    // 调用第 5 种构造函数
    pair <string, string> pair5(string("Python教程"), string("http://c.biancheng.net/python/"));  
   
    cout << "pair1: " << pair1.first << " " << pair1.second << endl;
    cout << "pair2: "<< pair2.first << " " << pair2.second << endl;
    cout << "pair3: " << pair3.first << " " << pair3.second << endl;
    cout << "pair4: " << pair4.first << " " << pair4.second << endl;
    cout << "pair5: " << pair5.first << " " << pair5.second << endl;
    return 0;
}

int pair_compare() {
    pair <string, int> pair1("STL教程", 20);
    pair <string, int> pair2("C++教程", 20);
    pair <string, int> pair3("C++教程", 30);
    //pair1和pair2的key不同，value相同
    if (pair1 != pair2) {
        cout << "pair != pair2" << endl;
    }
    //pair2和pair3的key相同，value不同
    if (pair2 != pair3) {
        cout << "pair2 != pair3" << endl;
    }
    return 0;
}

int pair_swap() {
    pair <string, int> pair1("pair", 10);                   
    pair <string, int> pair2("pair2", 20);
    //交换 pair1 和 pair2 的键值对
    pair1.swap(pair2);
    cout << "pair1: " << pair1.first << " " << pair1.second << endl;
    cout << "pair2: " << pair2.first << " " << pair2.second << endl;
    return 0;
}
/*
    template < class Key,                                     // 指定键（key）的类型
               class T,                                       // 指定值（value）的类型
               class Compare = less<Key>,                     // 指定排序规则
               class Alloc = allocator<pair<const Key,T> >    // 指定分配器对象的类型
               > class map;

    std::map<std::string, int>myMap;
        std::map<std::string, int>myMap{ {"C语言教程",10},{"STL教程",20} };
        std::map<std::string, int>myMap{std::make_pair("C语言教程",10),std::make_pair("STL教程",20)};
    std::map<std::string, int>newMap(myMap);
        std::map<std::string, int>myMap{ {"C语言教程",10},{"STL教程",20} };
        std::map<std::string, int>newMap(++myMap.begin(), myMap.end());
        std::map<std::string, int>myMap{ {"C语言教程",10},{"STL教程",20} };
    std::map<std::string, int, std::less<std::string> >myMap{ {"C语言教程",10},{"STL教程",20} };
*/

int map_emplace() {
    //创建空 map 容器，默认根据个键值对中键的值，对键值对做降序排序
    std::map<std::string, std::string, std::greater<std::string>>myMap;
    //调用 emplace() 方法，直接向 myMap 容器中指定位置构造新键值对
    myMap.emplace("C语言教程","http://c.biancheng.net/c/");
    myMap.emplace("Python教程", "http://c.biancheng.net/python/");
    myMap.emplace("STL教程", "http://c.biancheng.net/stl/");
    //输出当前 myMap 容器存储键值对的个数
    cout << "myMap size==" << myMap.size() << endl;
    //判断当前 myMap 容器是否为空
    if (!myMap.empty()) {
        //借助 myMap 容器迭代器，将该容器的键值对逐个输出
        for (auto i = myMap.begin(); i != myMap.end(); ++i) {
            cout << i->first << " " << i->second << endl;
        }
    }  
    return 0;
}

int first()
{
    
    //创建一个空的 map 关联式容器，该容器中存储的键值对，其中键为 string 字符串，值也为 string 字符串类型
    map<string, string> mymap;
    //向 mymap 容器中添加数据
    mymap["http://c.biancheng.net/c/"] = "C语言教程";
    mymap["http://c.biancheng.net/python/"] = "Python教程";
    mymap["http://c.biancheng.net/java/"] = "Java教程";
    //使用 map 容器的迭代器，遍历 mymap 容器，并输出其中存储的各个键值对
    for (map<string, string>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
        //输出各个元素中的键和值
        cout << it->first << " => " << it->second << '\n';
    }
    return 0;
}

int map_find() {
    //创建并初始化 map 容器
    std::map<std::string, std::string>myMap{ {"STL教程","http://c.biancheng.net/stl/"},
                                             {"C语言教程","http://c.biancheng.net/c/"},
                                             {"Java教程","http://c.biancheng.net/java/"} };
    //查找键为 "Java教程" 的键值对
    auto iter = myMap.find("Java教程");
    //从 iter 开始，遍历 map 容器
    for (; iter != myMap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}

    // lower_bound(key) 返回的是指向第一个键不小于 key 的键值对的迭代器；
    // upper_bound(key) 返回的是指向第一个键大于 key 的键值对的迭代器；

int lower_bound_upper_bound() {
    //创建并初始化 map 容器
    std::map<std::string, std::string>myMap{ {"STL教程","http://c.biancheng.net/stl/"},
                                             {"C语言教程","http://c.biancheng.net/c/"},
                                             {"Java教程","http://c.biancheng.net/java/"} };
    //找到第一个键的值不小于 "Java教程" 的键值对
    auto iter = myMap.lower_bound("Java教程");
    cout << "lower：" << iter->first << " " << iter->second << endl;
   
    //找到第一个键的值大于 "Java教程" 的键值对
    iter = myMap.upper_bound("Java教程");
    cout <<"upper：" << iter->first << " " << iter->second << endl;
    return 0;
}

int map_equal_range() {
    //创建并初始化 map 容器
    std::map<string, string>myMap{ {"STL教程","http://c.biancheng.net/stl/"},
                                   {"C语言教程","http://c.biancheng.net/c/"},
                                   {"Java教程","http://c.biancheng.net/java/"} };
    //创建一个 pair 对象，来接收 equal_range() 的返回值
    pair <std::map<string, string>::iterator, std::map<string, string>::iterator> myPair = myMap.equal_range("C语言教程");
    //通过遍历，输出 myPair 指定范围内的键值对
    for (auto iter = myPair.first; iter != myPair.second; ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}

int operate_()
{
    std::map<string, string> mymap{ {"STL教程","http://c.biancheng.net/java/"} };
    //获取已存储键值对中，指定键对应的值
    cout << mymap["STL教程"] << endl;
    //向 map 容器添加新键值对
    mymap["Python教程"] = "http://c.biancheng.net/python/";
    //修改 map 容器已存储键值对中，指定键对应的值
    mymap["STL教程"] = "http://c.biancheng.net/stl/";
    for (auto iter = mymap.begin(); iter != mymap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
   
    return 0;
}

int map_insert()
{
    //创建空的 map 容器
    std::map<std::string, std::string>mymap;
    //向 mymap 容器中添加 3 个键值对
    mymap.insert({ {"STL教程", "http://c.biancheng.net/stl/"},
                   { "C语言教程","http://c.biancheng.net/c/" },
                   { "Java教程","http://c.biancheng.net/java/" } });
    for (auto iter = mymap.begin(); iter != mymap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }

    typedef map<string, string> mstr;
    //创建要添加的默认键值对元素
    pair<mstr::iterator, bool>res = mymap.insert(mstr::value_type("STL教程", string()));
    //将新键值对的值赋值为指定的值
    res.first->second = "http://c.biancheng.net/java/";

        //operator[]
    mymap["STL教程"] = "http://c.biancheng.net/stl/";
    //insert()
    std::pair<string, string> STL = { "Java教程","http://c.biancheng.net/python/" };
    mymap.insert(STL).first->second = "http://c.biancheng.net/java/";
    return 0;
}

int map_emplace()
{
    //创建并初始化 map 容器
    std::map<string, string>mymap;
    //插入键值对
    pair<map<string, string>::iterator, bool> ret = mymap.emplace("STL教程", "http://c.biancheng.net/stl/");
    cout << "1、ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //插入新键值对
    ret = mymap.emplace("C语言教程", "http://c.biancheng.net/c/");
    cout << "2、ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //失败插入的样例
    ret = mymap.emplace("STL教程", "http://c.biancheng.net/java/");
    cout << "3、ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    return 0;
}
int map_emplace_hint()
{
    //创建并初始化 map 容器
    std::map<string, string>mymap;
    //指定在 map 容器插入键值对
    map<string, string>::iterator iter = mymap.emplace_hint(mymap.begin(),"STL教程", "http://c.biancheng.net/stl/");
    cout << iter->first << " " << iter->second << endl;
    iter = mymap.emplace_hint(mymap.begin(), "C语言教程", "http://c.biancheng.net/c/");
    cout << iter->first << " " << iter->second << endl;
    //插入失败样例
    iter = mymap.emplace_hint(mymap.begin(), "STL教程", "http://c.biancheng.net/java/");
    cout << iter->first << " " << iter->second << endl;
    return 0;
}

// 和 map 容器的区别在于，multimap 容器中可以同时存储多（≥2）个键相同的键值对。
std::multimap<std::string, std::string>mymultimap;
//借助 pair 类模板的构造函数来生成各个pair类型的键值对
multimap<string, string>mymultimap{
    pair<string,string>{"C语言教程", "http://c.biancheng.net/c/"},
    pair<string,string>{ "Python教程", "http://c.biancheng.net/python/"},
    pair<string,string>{ "STL教程", "http://c.biancheng.net/stl/"}
};

//调用 make_pair() 函数，生成键值对元素
//创建并初始化 multimap 容器
multimap<string, string>mymultimap{
    make_pair("C语言教程", "http://c.biancheng.net/c/"),
    make_pair("Python教程", "http://c.biancheng.net/python/"),
    make_pair("STL教程", "http://c.biancheng.net/stl/")
};
//创建一个会返回临时 multimap 对象的函数
multimap<string, string> dismultimap() {
    multimap<string, string>tempmultimap{ {"C语言教程", "http://c.biancheng.net/c/"},{"Python教程", "http://c.biancheng.net/python/"} };
    return tempmultimap;
}  
//调用 multimap 类模板的移动构造函数创建 newMultimap 容器
multimap<string, string>newmultimap(dismultimap());
int multimap_func()
{
    //创建并初始化 multimap 容器
    multimap<char, int>mymultimap{ {'a',10},{'b',20},{'b',15}, {'c',30} };
    //输出 mymultimap 容器存储键值对的数量
    cout << mymultimap.size() << endl;
    //输出 mymultimap 容器中存储键为 'b' 的键值对的数量
    cout << mymultimap.count('b') << endl;
    for (auto iter = mymultimap.begin(); iter != mymultimap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}

int main()
{
    
    map_emplace();
    return 0;
}