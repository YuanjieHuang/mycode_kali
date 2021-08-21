　　//文件名：16-3.cpp
　　//顺序容器的使用示例
　　int main()
　　{   seqList<int>  sq(10);		//定义一个存放整型对象的顺序容器，初始容量为10个对象
　　    seqList<int>::Itr itr1;	//定义一个对应的迭代器类的对象
　　 
　　    for (int i = 0; i < 10; ++i) sq.push_back(2 * i + 1);
　　
　　    cout << "用下标运算符输出:\n";
　　    for (i = 0; i < 10;  ++i) cout << sq[i] << '\t';
　　
　　    cout << "用迭代器输出:\n";
　　    for (itr1 = sq.begin() ; itr1 != sq.end();  ++itr1)  cout << *itr1 << '\t';
　　
　　    //插入0,2,4,6,8,10,12,14,16,18
　　    for (itr1 = sq.begin(), i = 0 ; i < 20; ++itr1, ++itr1, i += 2) sq.insert(itr1, i);
　　
　　    cout << "插入0,2,4,6,8,10,12,14,16,18后:\n";
　　    for (itr1 = sq.begin() ; itr1 != sq.end();  ++itr1)  cout << *itr1 << '\t';
　　
　　    //删除0,2,4,6,8,10,12,14,16,18
　　    for (itr1 = sq.begin(); itr1 != sq.end(); ++itr1)  sq.erase(itr1);
　　
　　    cout << "删除0,2,4,6,8,10,12,14,16,18后:\n";
　　    for (itr1 = sq.begin() ; itr1 != sq.end();  ++itr1)  cout << *itr1 << '\t';
　　
　　    return 0;
　　}
　　
