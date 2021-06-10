/*
priority_queue<Type, Container, Functional>

当需要用自定义的数据类型时才需要传入 Type, Container, Functional 这三个参数，使用基本数据类型时，只需要传入数据类型，默认是大顶堆。

    Type: 数据类型
    Container: 容器类型（Container必须是用数组实现的容器，比如vector, deque等等，但不能用 list，STL 里面默认用的是 vector）
    Functional: 比较的方式

// 升序队列，小顶堆
priority_queue <int,vector<int>,greater<int> > q;
// 降序队列，大顶堆
priority_queue <int,vector<int>,less<int> >q;
// greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数，其实就是在类中实现一个operator()方法，这个类就有了类似函数的行为，就是一个仿函数类了）


*/
#include<iostream>
#include <queue>
using namespace std;
int baseTypeAsElem() 
{
    // 对于基础类型 默认是大顶堆
    // 等同于 priority_queue<int, vector<int>, less<int> > a;
    priority_queue<int> a;
    // 等同于 priority_queue<string, vector<string> less<string> > b;
    priority_queue<string> b;
    // 这里一定要有空格，不然成了右移运算符
    priority_queue<int, vector<int>, greater<int> > c;  //这样就是小顶堆
    for (int i = 0; i < 5; i++) 
    {
        a.push(i);
        c.push(i);
    }
    while (!a.empty()) 
    {
        cout << a.top() << ' ';
        a.pop();
    } 
    cout << endl;
    while (!c.empty()) 
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;
    b.push("a");
    b.push("b");
    b.push("c");
    while (!b.empty()) 
    {
        cout << b.top() << ' ';
        b.pop();
    } 
    cout << endl;
    return 0;
}

int pairAsElem() 
{
    priority_queue<pair<int, int> > a;
    pair<int, int> b(1, 2);
    pair<int, int> c(1, 3);
    pair<int, int> d(2, 5);
    pair<int, int> e(3, 4);
    a.push(d);
    a.push(c);
    a.push(b);
    a.push(e);
    while (!a.empty()) 
    {
        cout << a.top().first << ' ' << a.top().second << '\n';
        a.pop();
    }
    return 0;
}
/*自定义类型作为队列元素*/
//方法1
struct tmp1 //运算符重载<
{
    int x;
    tmp1(int a) {x = a;}
    bool operator<(const tmp1& a) const
    {
        return x < a.x; //大顶堆
    }
};

//方法2
struct tmp2 //重写仿函数
{
    bool operator() (tmp1 a, tmp1 b) 
    {
        return a.x < b.x; //大顶堆
    }
};

int selfDefinedTypeAsElem() 
{
    tmp1 a(1);
    tmp1 b(2);
    tmp1 c(3);
    priority_queue<tmp1> d;
    d.push(b);
    d.push(c);
    d.push(a);
    while (!d.empty()) 
    {
        cout << d.top().x << '\n';
        d.pop();
    }
    cout << endl;

    priority_queue<tmp1, vector<tmp1>, tmp2> f;
    f.push(b);
    f.push(c);
    f.push(a);
    while (!f.empty()) 
    {
        cout << f.top().x << '\n';
        f.pop();
    }
    return 0;
}

int main()
{
     baseTypeAsElem() ;
     pairAsElem() ;
     selfDefinedTypeAsElem() ;
    return 0;
}