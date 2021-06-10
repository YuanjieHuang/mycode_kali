　　//文件名：16-6.cpp
　　//listLink的使用示例
　　int main()
　　{   linkList<int>  lq;			//定义一个整型的容器lq
　　    linkList<int>::Itr itr1 = lq.GetHead();	//定义一个迭代器，并让它指向lq的头结点
　　 
　　    for (int i = 0; i < 10; ++i) lq.insert(itr1, 2 * i + 1);
　　
　　    cout << "用迭代器输出:\n";
　　    for (itr1 = lq.begin() ; itr1();  ++itr1)  cout << *itr1 << '\t';
　　
　　    //插入0,2,4,6,8,10,12,14,16,18
　　    for (itr1 = lq.GetHead(), i = 0 ; i < 20;  ++itr1, i += 2) lq.insert(itr1, i);
　　
　　    cout << "插入0,2,4,6,8,10,12,14,16,18后:\n";
　　    for (itr1 = lq.begin() ; itr1();  ++itr1) cout << *itr1 << '\t';
　　
　　    //删除0,2,4,6,8,10,12,14,16,18
　　    for (itr1 = lq.GetHead(); itr1(); ++itr1) lq.erase(itr1);
　　
　　    cout << "删除0,2,4,6,8,10,12,14,16,18后:\n";
　　    for (itr1 = lq.begin() ; itr1();  ++itr1) cout << *itr1 << '\t';
　　
　　    return 0;
　　}
　　
