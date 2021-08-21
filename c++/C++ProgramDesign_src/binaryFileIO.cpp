// **********************************************************
// binaryFileIO.cpp
// 功能：说明利用ifstream和ofstream进行二进制文件I/O
// **********************************************************
#include <iostream>
#include <fstream>                
using namespace std;
int main(  )
{
	int a[10]={10,20,30,40,50,60,70,80,90,100};
	int b[10];
    	int i;
    	ifstream inFile;                      	//①
    	ofstream outFile;                     	//①
	outFile.open( "c:\\1.dat", ios::binary );   	//②
	for( i = 0; i < 10; i++ ) {
		outFile.write( (char*)&a[i], sizeof( a[i] ) );  	//③
	}                              
    	outFile.close();                             	//④
	inFile.open(  "c:\\1.dat", ios::binary );    	//②
	for( i = 0; i < 10; i++ ) {
		inFile.read(  (char*)&b[i], sizeof( b[i] ) );  	//⑤      
	}   
	inFile.close();                              	//④                        
    	for ( i = 0; i < 10; i++)
		cout << b[i] << "  " ;
	cout << endl << endl;
	return 0;
}
