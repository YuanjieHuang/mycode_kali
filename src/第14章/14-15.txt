　　void addBook() {
　　    char ch[20];
　　    Book *bp;
　　    ofstream outfile("book",ofstream::app);	//以app方式打开文件
　　
　　    Book::addTotal();						//最大的馆藏号加1
　　    cout << "请输入书名："; cin >> ch;
　　    bp = new Book(ch);
　　
　　    outfile.write( reinterpret_cast<const char *>(bp), sizeof(*bp));
　　    delete bp;
　　    outfile.close();
　　}
　　
