    #include <iostream>
    #include <vector>
    #include<algorithm>
    #include<queue>
    using namespace std;
    
    // template <typename T1, typename T2 >
    void display(vector<int>& val) {
        for (auto v : val) {
            cout << v << " ";
        }
        cout << endl;
    }
    void display(priority_queue<int> val) {
        while (!val.empty())
        {
            cout<<val.top()<<" ";
            val.pop();
        }
        cout << endl;
    }

    int priority_queue_method()
    {
        //创建优先级队列
        std::vector<int>values{ 2,1,3,4 };
        display(values);
        std::priority_queue<int>copy_values(values.begin(), values.end());
        display(copy_values);
        //添加元素
        copy_values.push(5);
        display(copy_values);
        //移除元素
        copy_values.pop();
        display(copy_values);
        return 0;
    }
    int heap_method()
    {
        vector<int>values{ 2,1,3,4 };
        //建立堆
        make_heap(values.begin(), values.end());//{4,2,3,1}
        display(values);
        //添加元素
        cout << "添加元素：\n";
        values.push_back(5);
        display(values);
        push_heap(values.begin(), values.end());//{5,4,3,1,2}
        display(values);
        //移除元素
        cout << "移除元素：\n";
        pop_heap(values.begin(), values.end());//{4,2,3,1,5}
        display(values);
        values.pop_back();
        display(values);
        cout<<endl;
        return 0;
    }

    int main()
    {
        // vector<int>::iterator i;
        heap_method();
        priority_queue_method();
        return 0;
    }