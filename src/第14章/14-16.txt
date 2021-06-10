　　void borrowBook()
　　{   int bookNo, readerNo;
　　    fstream iofile("book");					//以读写方式打开文件
　　    Book bk;
　　
　　    cout << "请输入书号和读者号："; cin >> bookNo >> readerNo;
　　
　　    iofile.seekg((bookNo - 1) * sizeof(book));	//按照馆藏号定位到所读记录
　　    iofile.read( reinterpret_cast<char *> (&bk), sizeof(Book) );
　　                                                //读一条记录，存入对象bk
　　
　　    bk.borrow(readerNo);						//调用成员函数修改借书标记字段
　　
　　    iofile.seekp((bookNo - 1) * sizeof(Book));	//按照馆藏号定位到所写记录
　　    iofile.write(reinterpret_cast<const char *>(&bk), sizeof(Book));	//更新记录  
　　
　　    iofile.close();
　　}
　　
