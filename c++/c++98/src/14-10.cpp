#include <fstream>
#include <iostream>
using namespace std;

int main()
{   
    ifstream fin("test");
    char s[80];
    int i;
    float x;

    if (!fin) {cout << "cannot open input file\n"; return 1;}
    fin >> i >> x >> s; 
    cout << i << " " << x << s;
    fin.close(); 
 
    return 0; 
}