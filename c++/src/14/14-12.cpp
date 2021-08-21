　　//文件名：book.h
　　//Book类的设计
　　#ifndef _book_h
　　#define _book_h
　　
　　#include <cstring>
　　#include <iostream>
　　#include <iomanip>
　　#include <fstream>
　　using namespace std;
　　
　　class Book {
　　    int no;
　　    char name[20];
　　    int borrowed;
　　    static int no_total;
　　public:
　　    Book(const char *s = "") ;
　　    void borrow(int readerNo);
　　    void Return(); 
　　    void display(); 
　　    static void resetTotal(); 
　　    static void addTotal(); 
　　};
　　#endif
　　
　　//book.cpp
　　#include "book.h"
　　
　　Book::Book(const char *s)  {no = no_total; borrowed = 0; strcpy(name,s);}
　　
　　void Book::borrow(int readerNo)
　　{   if (borrowed != 0) cerr << "本书已被借，不能重复借\n"; else borrowed = readerNo;  }
　　
　　void Book::Return()
　　{   if (borrowed == 0) cerr << "本书没有被借，不能还\n";  else  borrowed = 0; }
　　
　　void Book::display() 
　　{   cout << setw(10) << no << setw(20) << name << setw(10) << borrowed << endl;}
　　
　　void Book::resetTotal() {   no_total = 0;}
　　void Book::addTotal() {   ++no_total;}
　　int Book::no_total = 0;
　　
