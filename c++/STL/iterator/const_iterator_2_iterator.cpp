    #include <iostream>
    #include <vector>
    using namespace std;
    int main()
    {
        vector<int>value{ 1,2,3,4,5 };
        //定义一个 const_iterator 类型的迭代器，其指向最后一个元素
        vector<int>::const_iterator citer = --value.cend();
        //初始化一个非 const 迭代器，另其指向
        vector<int>::iterator iter = value.begin();
        //将 iter 变成和 citer 同样指向的迭代器
        advance(iter, distance<vector<int>::const_iterator>(iter, citer)); 
        cout <<"*citer = " << *citer << endl;
        cout << "*iter = " << *iter << endl;
        return 0;
    }
    /*
    //将 const_iterator 转换为 iterator
advance(iter, distance<cont<T>::const_iterator>(iter,citer));
//将 const_reverse_iterator 转换为 reverse_iterator
advance(iter, distance<cont<T>::const_reverse_iterator>(iter,citer));
*/