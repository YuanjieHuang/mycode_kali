　　void displayBook()
　　{   ifstream infile("book");
　　    Book bk;
　　
　　    infile.read(reinterpret_cast<char *> (&bk), sizeof(Book));
　　
　　    while (!infile.eof()) { //顺序读文件，直到结束
　　        bk.display(); //显示当前书目信息的内容
　　        infile.read(reinterpret_cast<char *> (&bk), sizeof(Book));
　　    }
　　    infile.close();
　　}
　　
