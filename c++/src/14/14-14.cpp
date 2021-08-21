　　void initialize() {
　　    ofstream outfile("book");	//清空文件book
　　    Book::resetTotal();		//调用Book类的静态成员函数，将最大的馆藏号置为0
　　    outfile.close();
　　}
　　
