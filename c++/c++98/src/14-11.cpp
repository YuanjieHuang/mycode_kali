//文件的随机读写
#include <iostream>
#include <fstream>
using namespace std;

int main()
{   
    fstream in("file");
    int i;
 
    if (!in) {cerr << "open file error\n"; return 1;}

    in.seekp(10);	//重新定位写文件指针
    in << 20;		//改写文件的内容

    in.seekg(0);	//读文件定位指针移到文件起始处
    while (in >> i) cout << i << ' '; 
    in.close();

    return 0;
}