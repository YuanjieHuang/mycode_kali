　　//借书成功，返回true，否则返回false
　　bool readerTeacher::bookBorrow(int bookNo)	
　　{   if (borrowed == MAX) return false;
　　        else record[borrowed++] = bookNo; 
　　    return true;
　　}
　　
　　//还书成功，返回true，否则返回false
　　bool readerTeacher::bookReturn(int bookNo)
　　{   int i;
　　    for (i=0; i < borrowed; ++i) if (record[i] == bookNo) break;
　　    if (i == borrowed) return false;
　　    while (++i < borrowed)  record[i-1] = record[i];
　　    --borrowed;
　　    return true;
　　}
　　
　　//显示已借书信息
　　void readerTeacher::show()
　　{   for (int i = 0; i < borrowed; ++i)  cout << record[i] << '\t'; }
　　
