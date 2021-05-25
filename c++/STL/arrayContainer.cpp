#include <iostream>
//需要引入 array 头文件
#include <array>
#include <cstring>
using namespace std;
void array_construct()
{
    std::array<double, 10> values;//各个元素的值是不确定的（array 容器不会做默认初始化操作）。
    std::array<double, 10> values {};//容器中所有的元素都会被初始化为 0.0。
    std::array<double, 10> values {0.5,1.0,1.5,2.0};//这里只初始化了前 4 个元素，剩余的元素都会被初始化为 0.0
}
int array_get()
{
    std::array<int, 4> values{};
    //初始化 values 容器为 {0,1,2,3}
    for (int i = 0; i < values.size(); i++) {
        values.at(i) = i;
    }
    //使用 get() 重载函数输出指定位置元素
    cout << get<3>(values) << endl;
    //如果容器不为空，则输出容器中所有的元素
    if (!values.empty()) {
        for (auto val = values.begin(); val < values.end(); val++) {
            cout << *val << " ";
        }
    }
    return 0;
}

void my_array_data()
{
    array<double,5> values{1.0,2.0,3.0};
    array<int, 5> words{1,2,3,4,5};
    values[4] = values[3] + values[1];
    // values.at (4) = values.at(3) + 2.O*values.at(1);
    cout << *( words.data()+1);
}

int test()
{
    array<int, 5>values;
    int h = 1;
    //auto first = std::begin(values);
    //auto last = std::end (values);

    // auto first = values.begin();
    // auto last = values.end();

    // auto first = values.cbegin();
    // auto last = values.cend();

    //初始化 values 容器为{1,2,3,4,5}
// 需要注意的是，在使用反向迭代器进行 ++ 或 -- 运算时，++ 指的是迭代器向左移动一位，-- 指的是迭代器向右移动一位，即这两个运算符的功能也“互换”了。

    auto first = values.rbegin();
    auto last = values.rend(); 

    while (first != last)
    {
        *first = h;
        ++first;
        h++;
    }
  
    first = values.rbegin();
    while (first != last)
    {
        cout << *first << " ";//可以像使用普通指针那样使用迭代器对象
        ++first;
    }
    return 0; 
}
void array_cpy()
{
    array<char, 50>a{1,2,3};
    // strcpy(&a[0], "http://c.biancheng.net/stl");
    strcpy(a.data(), "http://c.biancheng.net/stl");
    printf("%s\n", &a[0]);
}

int array_swap()
{
    array<char, 50>addr1{"http://c.biancheng.net"};
    array<char, 50>addr2{ "huangyuanjie.com" };
    addr1.swap(addr2);
    printf("addr1 is：%s\n", addr1.data());
    printf("addr2 is：%s\n", addr2.data());
    return 0;
}

int array_assign()
{
    array<char, 50>addr1{};
    array<char, 50>addr2{ "http://c.biancheng.net/stl" };
    addr1 = addr2;
    printf("%s", addr1.data());
    return 0;
}

int array_compare()
{
    array<char, 50>addr1{ "http://c.biancheng.net" };
    array<char, 50>addr2{ "http://c.biancheng.net/stl" };
    if (addr1 == addr2) {
        std::cout << "addr1 == addr2" << std::endl;
    }
    if (addr1 < addr2) {
        std::cout << "addr1 < addr2" << std::endl;
    }
    if (addr1 > addr2) {
        std::cout << "addr1 > addr2" << std::endl;
    }
    return 0;
}

int main()
{
    array_cpy();
    array_swap();
    array_assign();
    array<int, 5> values1;
    array<int, 5> values2;
    //初始化 values1 为 {0,1,2,3,4}
    for (size_t i = 0; i < values1.size(); ++i)
    {
        values1.at(i) = i;
    }
    cout << "values1[0] is : " << values1[0] << endl;
    cout << "values1[1] is : " << values1.at(1) << endl;
    cout << "values1[2] is : " << get<2>(values1) << endl;
    //初始化 values2 为{10，11，12，13，14}
    int initvalue = 10;
    for (auto& value : values2)
    {
        value = initvalue;
        initvalue++;
    }
    cout <<  "Values1 is : ";
    for (auto i = values1.begin(); i < values1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl << "Values2 is : ";
    for (auto i = values2.begin(); i < values2.end(); i++) {
        cout << *i << " ";
    }

    
    return 0;
}