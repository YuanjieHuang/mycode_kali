    #include<iostream>
    #include<set>
    #include<string>
    using namespace std;
    class student {
    public:
        student(string name, int id, int age) :name(name), id(id), age(age) {
        }
        const int& getid() const {
            return id;
        }
        void setname(const string name){
            this->name = name;
        }
        string getname() const{
            return  name;
        }
        void setage(int age){
            this->age = age;
        }
        int getage() const{
            return  age;
        }
        void display()const {
            cout << id << " " << name << " " << age << endl;
        }
    private:
        string name;
        int id;
        int age;
    };
    //自定义 myset 容器的排序规则
    class cmp {
    public:
        bool operator ()(const student &stua, const student &stub) {
            //按照字符串的长度，做升序排序(即存储的字符串从短到长)
            return  stua.getid() < stub.getid();
        }
    };
    int main() {
        set<student, cmp> mymap{ {"zhangsan",10,20},{"lisi",20,21},{"wangwu",15,19} };
        set<student>::iterator iter = mymap.begin();
        //直接将 {"zhangsan",10,20} 中的 "zhangsan" 修改为 "xiaoming"
        const_cast<student&>(*iter).setname("xiaoming");
       
        while (iter != mymap.end()) {
            (*iter).display();
            ++iter;
        }
        return 0;
    }
    // 再次强调，虽然使用 const_cast 能直接修改 set 或者 multiset 容器中的元素，但一定不要修改元素的键！
    // 如果要修改，只能采用“先删除，再添加”的方式。
    // 另外，不要试图以同样的方式修改 map 或者 multimap 容器中键值对的键，这违反了 C++ STL 标准的规定。