    #include <iostream>
    #include <set>      // set
    #include <string>       // string
    using namespace std;
    //自定义类
    class myString {
    public:
        //定义构造函数，向 myset 容器中添加元素时会用到
        myString(string tempStr) :str(tempStr) {};
        //获取 str 私有对象，由于会被私有对象调用，因此该成员方法也必须为 const 类型
        string getStr() const;
    private:
        string str;
    };
    string myString::getStr() const{
        return this->str;
    }
    //重载 < 运算符，参数必须都为 const 类型
    bool operator <(const myString &stra, const myString & strb) {
        //以字符串的长度为标准比较大小
        return stra.getStr().length() < strb.getStr().length();
    }
    int main() {
        //创建空 set 容器，仍使用默认的 less<T> 排序规则
        std::set<myString>myset;
        //向 set 容器添加元素，这里会调用 myString 类的构造函数
        myset.emplace("http://c.biancheng.net/stl/");
        myset.emplace("http://c.biancheng.net/c/");
        myset.emplace("http://c.biancheng.net/python/");
        //
        for (auto iter = myset.begin(); iter != myset.end(); ++iter) {
            myString mystr = *iter;
            cout << mystr.getStr() << endl;
        }
        return 0;
    }