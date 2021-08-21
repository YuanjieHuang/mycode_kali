#include <iostream>
using namespace std;

int main()
{   
    char *ptr = "abcdef";
    cout << "ptr指向的内容为： " << ptr << endl;
    cout << "ptr中保存的地址为：" << (void*)ptr << endl;
    return 0;
}
