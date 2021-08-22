/*
std::set<std::string> myset;
    std::set<std::string> myset{"http://c.biancheng.net/java/",
                                "http://c.biancheng.net/stl/",
                                "http://c.biancheng.net/python/"};

    std::set<std::string> copyset(myset);
    //等同于
    //std::set<std::string> copyset = myset

set<string> retSet() {
std::set<std::string> myset{ "http://c.biancheng.net/java/",
                        "http://c.biancheng.net/stl/",
                        "http://c.biancheng.net/python/" };
return myset;
}
std::set<std::string> copyset(retSet());
//或者
//std::set<std::string> copyset = retSet();

std::set<std::string> copyset(++myset.begin(), myset.end());
*/
#include <iostream>
#include <set>
#include <string>
using namespace std;

int set_find()
{
    //创建并初始化set容器
    std::set<std::string> myset{ "http://c.biancheng.net/java/",
                                 "http://c.biancheng.net/stl/",
                                 "http://c.biancheng.net/python/"
    };
   
    set<string>::iterator iter = myset.find("http://c.biancheng.net/python/");
    for (;iter != myset.end();++iter)
    {
        cout << *iter << endl;
    }
    return 0;
}

/*
//删除 set 容器中值为 val 的元素
size_type erase (const value_type& val);
//删除 position 迭代器指向的元素
iterator  erase (const_iterator position);
//删除 [first,last) 区间内的所有元素
iterator  erase (const_iterator first, const_iterator last);

*/

int set_erase()
{
    //创建并初始化 set 容器
    std::set<int>myset{1,2,3,4,5};
    cout << "myset size = " << myset.size() << endl;
   
    //1) 调用第一种格式的 erase() 方法
    int num = myset.erase(2); //删除元素 2，myset={1,3,4,5}
    cout << "1、myset size = " << myset.size() << endl;
    cout << "num = " << num << endl;
    //2) 调用第二种格式的 erase() 方法
    set<int>::iterator iter = myset.erase(myset.begin()); //删除元素 1，myset={3,4,5}
    cout << "2、myset size = " << myset.size() << endl;
    cout << "iter->" << *iter << endl;
    //3) 调用第三种格式的 erase() 方法
    set<int>::iterator iter2 = myset.erase(myset.begin(), --myset.end());//删除元素 3,4，myset={5}
    cout << "3、myset size = " << myset.size() << endl;
    cout << "iter2->" << *iter2 << endl;
    return 0;
}

int main()
{
    //创建空set容器
    std::set<std::string> myset;
    //空set容器不存储任何元素
    cout << "1、myset size = " << myset.size() << endl;
    //向myset容器中插入新元素
    myset.insert("http://c.biancheng.net/java/");
    myset.insert("http://c.biancheng.net/stl/");
    myset.insert("http://c.biancheng.net/python/");
    cout << "2、myset size = " << myset.size() << endl;
    //利用双向迭代器，遍历myset
    for (auto iter = myset.begin(); iter != myset.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}