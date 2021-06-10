程序清单10-2
// **********************************************************
// fileCopy.cpp
// 功能：演示利用文件流实现文本文件的复制
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

     inFile >> c;                    	//①
     while( inFile ) {              	//②
		outFile << c; 
		inFile >> c;   			//③           
	}
	
	inFile.close();     
	outFile.close();    

    return 0;
}
