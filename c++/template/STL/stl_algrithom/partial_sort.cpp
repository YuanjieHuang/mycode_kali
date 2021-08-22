    #include <iostream>     // std::cout
    #include <algorithm>    // std::partial_sort std::partial_sort_copy
    #include <vector>       // std::vector
    #include <list>       // std::list
    using namespace std;
    //以普通函数的方式自定义排序规则
    bool mycomp1(int i, int j) {
        return (i > j);
    }
    //以函数对象的方式自定义排序规则
    class mycomp2 {
    public:
        bool operator() (int i, int j) {
            return (i > j);
        }
    };

    int nth_element_test() {
    std::vector<int> myvector{3,1,2,5,4};
    //默认的升序排序作为排序规则
    std::nth_element(myvector.begin(), myvector.begin()+2, myvector.end());
    cout << "第一次nth_element排序：\n";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }
    //自定义的 mycomp2() 或者 mycomp1 降序排序作为排序规则
    std::nth_element(myvector.begin(), myvector.begin() + 3, myvector.end(),mycomp1);
    cout << "\n第二次nth_element排序：\n";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }
    return 0;
}

    int partial_sort_test() {
        std::vector<int> myvector{ 3,2,5,4,1,6,9,7};
        //以默认的升序排序作为排序规则，将 myvector 中最小的 4 个元素移动到开头位置并排好序
        std::partial_sort(myvector.begin(), myvector.begin() + 4, myvector.end());
        cout << "第一次排序:\n";
        for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << *it << ' ';
        cout << "\n第二次排序:\n";
        // 以指定的 mycomp2 作为排序规则，将 myvector 中最大的 4 个元素移动到开头位置并排好序
        std::partial_sort(myvector.begin(), myvector.begin() + 4, myvector.end(), mycomp2());
        for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << *it << ' ';
        return 0;
    }

    int partial_sort_copy_test() {
        int myints[5] = { 0 };
        std::list<int> mylist{ 3,2,5,4,1,6,9,7 };
        //按照默认的排序规则进行部分排序
        std::partial_sort_copy(mylist.begin(), mylist.end(), myints, myints + 5);
        cout << "第一次排序：\n";
        for (int i = 0; i < 5; i++) {
            cout << myints[i] << " ";
        }
        //以自定义的 mycomp2 作为排序规则，进行部分排序
        std::partial_sort_copy(mylist.begin(), mylist.end(), myints, myints + 5, mycomp2());
        cout << "\n第二次排序：\n";
        for (int i = 0; i < 5; i++) {
            cout << myints[i] << " ";
        }
        return 0;
    }

    int is_sorted_test() {
    vector<int> myvector{ 3,1,2,4 };
    list<int> mylist{ 1,2,3,4 };
    //调用第 2 种语法格式的 is_sorted() 函数，该判断语句会得到执行
    if (!is_sorted(myvector.begin(), myvector.end(),mycomp2())) {
        cout << "开始对 myvector 容器排序" << endl;
        //对 myvector 容器做降序排序
        sort(myvector.begin(), myvector.end(),mycomp2());
        //输出 myvector 容器中的元素
        for (auto it = myvector.begin(); it != myvector.end(); ++it) {
            cout << *it << " ";
        }
    }
   
    //调用第一种语法格式的 is_sorted() 函数，该判断语句得不到执行
    if (!is_sorted(mylist.begin(), mylist.end())) {
        cout << "开始对 mylist 排序" << endl;
        //......
    }
    return 0;
}

int is_sorted_until_test() {
    vector<int> myvector{ 3,1,2,4 };
    list<int> mylist{ 1,2,3,4 };
    //如果返回值为 myvector.end()，则表明 myvector 容器中的序列符合 mycomp2() 规则
    if (is_sorted_until(myvector.begin(), myvector.end(),mycomp2()) != myvector.end()) {
        cout << "开始对 myvector 容器排序" << endl;
        //对 myvector 容器做降序排序
        sort(myvector.begin(), myvector.end(),mycomp2());
        //输出 myvector 容器中的元素
        for (auto it = myvector.begin(); it != myvector.end(); ++it) {
            cout << *it << " ";
        }
    }
   
    //该判断语句得不到执行
    if (is_sorted_until(mylist.begin(), mylist.end()) != mylist.end()) {
        cout << "开始对 mylist 排序" << endl;
        //......
    }
    return 0;
}

int merge_test() {
    //first 和 second 数组中各存有 1 个有序序列
    int first[] = { 5,10,15,20,25 };
    int second[] = { 7,17,27,37,47,57 };
    //用于存储新的有序序列
    vector<int> myvector(11);
    //将 [first,first+5) 和 [second,second+6) 合并为 1 个有序序列，并存储到 myvector 容器中。
    merge(first, first + 5, second, second + 6, myvector.begin());
    //输出 myvector 容器中存储的元素
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        cout << *it << ' ';
    }   
    return 0;
}

int inplace_merge_test() {
    //该数组中存储有 2 个有序序列
    int first[] = { 5,10,15,20,25,7,17,27,37,47,57 };
    //将 [first,first+5) 和 [first+5,first+11) 合并为 1 个有序序列。
    inplace_merge(first, first + 5,first +11);
    for (int i = 0; i < 11; i++) {
        cout << first[i] << " ";
    }
    return 0;
}

int find_test() {
    //find() 函数作用于普通数组
    char stl[] ="http://c.biancheng.net/stl/";
    //调用 find() 查找第一个字符 'c'
    char * p = find(stl, stl + strlen(stl), 'c');
    //判断是否查找成功
    if (p != stl + strlen(stl)) {
        cout << p << endl;
    }
    //find() 函数作用于容器
    std::vector<int> myvector{ 10,20,30,40,50 };
    std::vector<int>::iterator it;
    it = find(myvector.begin(), myvector.end(), 30);
    if (it != myvector.end())
        cout << "查找成功：" << *it;
    else
        cout << "查找失败";
    return 0;
}