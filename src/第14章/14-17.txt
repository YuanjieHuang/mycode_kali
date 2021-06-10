　　void returnBook()
　　{   int bookNo;
　　    fstream iofile("book");
　　    Book bk;
　　
　　    cout << "请输入书号："; cin >> bookNo ;
　　
　　    iofile.seekg((bookNo - 1) * sizeof(Book));
　　    iofile.read(reinterpret_cast<char *> (&bk), sizeof(Book));
　　
　　    bk.Return();		//复位借书标记
　　   
　　    iofile.seekp((bookNo - 1) * sizeof(Book));
　　    iofile.write( reinterpret_cast<const char *>(&bk), sizeof(Book));
　　
　　    iofile.close();
　　 }
　　
