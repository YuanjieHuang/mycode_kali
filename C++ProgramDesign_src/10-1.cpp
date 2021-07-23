// **********************************************************
// fileIO.cpp
// 功能：演示利用文件流实现文件I/O
// **********************************************************
#include <fstream>                	//①
using namespace std;
int main(  )
{
    int someInt;
    float someFloat;
    char someChar;
    ifstream  inFile;  	//②
    ofstream  outFile;  	//②
    inFile.open("source.txt");         	//③
    outFile.open("result.txt");        	//④
    inFile >>  someInt >> someFloat >> someChar;   	//⑤
    outFile <<  "The answer is: " << someInt*someFloat << endl;	//⑥
    inFile.close();     	//⑦
    outFile.close();    	//⑦
    return 0;
}
