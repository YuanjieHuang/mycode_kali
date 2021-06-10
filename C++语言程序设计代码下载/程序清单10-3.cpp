程序清单10-3
// **********************************************************
// fileCopyRevised.cpp
// 功能：演示利用文件流实现文本文件的完整复制
// **********************************************************

#include <fstream>                
using namespace std;

int main(  )
{
	char c;
	ifstream  inFile;  		      
	ofstream  outFile;  		      

     inFile.open("1.txt");         
     outFile.open("2.txt");        

     inFile.get(c);                     	//①
     while( inFile ) {                  	//②
		outFile << c; 
		inFile.get(c);     				//③           
	}
	
	inFile.close();     
	outFile.close();    

    return 0;
}
