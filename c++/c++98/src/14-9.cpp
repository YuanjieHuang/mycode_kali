//文件名：14-9.cpp
//写一个包含各种类型的数据的文件操作的示例
#include <fstream>
#include <iostream>
using namespace std;

int main()
{   
    ofstream fout("test");
    if (!fout){cerr <<"cannot open output file\n"; return 1;}
    fout<<10<<" "<<123.456<< "\"This is a text file\"\n";
    fout.close();
    return 0; 
}