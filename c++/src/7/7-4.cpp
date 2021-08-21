//文件名：7-4.cpp
//带参数的main函数示例
#include <iostream>
using namespace std;

int main(int argc,  char *argv[])
{   int i;

    cout << "argc=" << argc << endl;
    for(i=0; i<argc;  ++i) cout << "argv[" << i << "]="<< argv[i]  << endl;
    return 0;
}

