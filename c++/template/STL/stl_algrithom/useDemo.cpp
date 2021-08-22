#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <string>       // std::string
#include <vector>       // std::vector
#include <functional>
using namespace std;
class Address {
public:
    Address(string url) :url(url) {};
    void display() {
        cout << "url:" << this->url << endl;
    }
private:
    string url;
};
int mem_fun_ref_test() {
    vector<Address>adds{ Address("http://c.biancheng.net/stl/"),
                            Address("http://c.biancheng.net/java/"),
                            Address("http://c.biancheng.net/python/") };
    //手动编写循环结构
    cout << "first：\n";
    for (auto it = adds.begin(); it != adds.end(); ++it) {
        (*it).display();
    }
    //调用 STL 标准库中的算法函数
    cout << "second：\n";
    for_each(adds.begin(), adds.end(), mem_fun_ref(&Address::display));
    return 0;
}

    //自定义一元谓词函数
bool mycomp(int i) {
    return ((i % 2) == 1);
}
//以函数对象的形式定义一个 find_if() 函数的查找规则
namespace find_if_test
{
    class mycomp2 {
    public:
        bool operator()(const int& i) {
            return ((i % 2) == 1);
        }
    };
}//namespace
int find_if_test() {
    vector<int> myvector{ 4,2,3,1,5 };
    //调用 find_if() 函数，并以 IsOdd() 一元谓词函数作为查找规则
    vector<int>::iterator it = find_if(myvector.begin(), myvector.end(), find_if_test::mycomp2());
    cout << "*it = " << *it;
    return 0;
}
// find_if() 函数用于查找符合谓词函数规则的第一个元素，而 find_if_not() 函数则用于查找第一个不符合谓词函数规则的元素。
int find_if_not_test() {
    vector<int> myvector{4,2,3,1,5};
    //调用 find_if() 函数，并以 mycomp() 一元谓词函数作为查找规则
    vector<int>::iterator it = find_if_not(myvector.begin(), myvector.end(), mycomp);
    cout << "*it = " << *it;
    return 0;
}

//以普通函数的形式定义一个匹配规则
bool mycomp1(int i, int j) {
    return (i%j == 0);
}
//以函数对象的形式定义一个匹配规则
class mycomp3 {
public:
    bool operator()(const int& i, const int& j) {
        return (i%j == 0);
    }
};
int find_end_test() {
    vector<int> myvector{ 1,2,3,4,8,12,18,1,2,3 };
    int myarr[] = { 1,2,3 };
    //调用第一种语法格式
    vector<int>::iterator it = find_end(myvector.begin(), myvector.end(), myarr, myarr + 3);
    if (it != myvector.end()) {
        cout << "最后一个{1,2,3}的起始位置为：" << it - myvector.begin() << ",*it = " << *it << endl;
    }
    int myarr2[] = { 2,4,6 };
    //调用第二种语法格式
    it = find_end(myvector.begin(), myvector.end(), myarr2, myarr2 + 3, mycomp3());
    if (it != myvector.end()) {
        cout << "最后一个{2,3,4}的起始位置为：" << it - myvector.begin() << ",*it = " << *it;
    }
    return 0;
}

//自定义二元谓词函数，作为 find_first_of() 函数的匹配规则
bool mycomp(int c1, int c2) {
    return (c2 % c1 == 0);
}
//以函数对象的形式定义一个 find_first_of() 函数的匹配规则
class mycomp2 {
public:
    bool operator()(const int& c1, const int& c2) {
        return (c2 % c1 == 0);
    }
};
namespace adjacent_find_test
{
    //以创建普通函数的形式定义一个查找规则
    bool mycomp1(int i, int j) {
        return (i == j);
    }
    //以函数对象的形式定义一个查找规则
    class mycomp2{
    public:
        bool operator()(const int& _Left, const int& _Right){
            return (_Left == _Right);
        }
    };
}//namespace 
    int adjacent_find_test() {
        using namespace adjacent_find_test;
        std::vector<int> myvector{ 5,20,5,30,30,20,10,10,20 };
        //调用第一种语法格式
        std::vector<int>::iterator it = adjacent_find(myvector.begin(), myvector.end());
        if (it != myvector.end()) {
            cout << "one : " << *it << '\n';
        }
        //调用第二种格式，也可以使用 mycomp1
        it = adjacent_find(++it, myvector.end(), adjacent_find_test::mycomp2());
        if (it != myvector.end()) {
            cout << "two : " << *it;
        }
        return 0;
    }

int find_first_of_test() {
    char url[] = "http://c.biancheng.net/stl/";
    char ch[] = "stl";
    //调用第一种语法格式，找到 url 中和 "stl" 任一字符相同的第一个字符
    char *it = find_first_of(url, url + 27, ch, ch + 4);
    if (it != url + 27) {
        cout << "*it = " << *it << '\n';
    }
    vector<int> myvector{ 5,7,3,9 };
    int inter[] = { 4,6,8 };
    //调用第二种语法格式，找到 myvector 容器中和 3、5、7 任一元素有 c2%c1=0 关系的第一个元素
    vector<int>::iterator iter = find_first_of(myvector.begin(), myvector.end(), inter, inter + 3, mycomp2());
    if (iter != myvector.end()) {
        cout << "*iter = " << *iter;
    }
    return 0;
}

int search_test() {
    vector<int> myvector{ 1,2,3,4,8,12,18,1,2,3 };
    int myarr[] = { 1,2,3 };
    //调用第一种语法格式
    vector<int>::iterator it = search(myvector.begin(), myvector.end(), myarr, myarr + 3);
    if (it != myvector.end()) {
        cout << "第一个{1,2,3}的起始位置为：" << it - myvector.begin() << ",*it = " << *it << endl;
    }
    int myarr2[] = { 2,4,6 };
    //调用第二种语法格式
    it = search(myvector.begin(), myvector.end(), myarr2, myarr2 + 3, mycomp2());
    if (it != myvector.end()) {
        cout << "第一个{2,3,4}的起始位置为：" << it - myvector.begin() << ",*it = " << *it;
    }
    return 0;
}
void test()
{
    std::vector<int> ages {22, 19, 46, 75, 54, 19, 27, 66, 61, 33, 22, 19};
    int min_age{18};
    std::cout << "There are "<< (std::none_of(std::begin(ages), std::end(ages),[min_age](int age) { return age < min_age; }) ?
            "no": "some") << " people under " << min_age << std::endl;
    std::cout << "There are "<< (std::any_of(std::begin(ages), std::end(ages),[min_age] (int age) { return age < min_age;}) ? 
        "some":"no") <<" people under " << min_age << std::endl;
        int good_age{100};
    std::cout << (std::all_of(std::begin(ages), std::end(ages),[good_age] (int age) { return age < good_age; }) ?
        "None": "Some") << " of the people are centenarians." << std::endl;
    std::vector<int> ages {22, 19, 46, 75, 54, 19, 27, 66, 61, 33, 22, 19};
    int the_age{19};
    std::cout << "There are "<< std::count(std::begin(ages),std::end(ages),the_age)<< " people aged "<< the_age << std::endl;
    int max_age{60};
    std::cout << "There are "<< std::count_if(std::begin(ages), std::end(ages),[max_age](int age) { return age > max_age; }) << 
    " people aged over " << max_age << std::endl;
}