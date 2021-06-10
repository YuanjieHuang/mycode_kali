程序清单3-5
// ***************************************************************
// primeNumCount.cpp
// 计算1～10000的素数的个数和非素数的个数
// ***************************************************************

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int i, j;
	int primeCnt, nonPrimeCnt;

	primeCnt = 0;
	nonPrimeCnt = 0;
	for (i = 1; i <= 10000; i++) {
		if (i == 1 || i == 2 || i == 3)
			primeCnt++;
		else
			for (j = 2 ; j <= int(sqrt(i)); j++) {
				if (i % j == 0) {
					  nonPrimeCnt++;
					  break;			   
				}
				else {
					  if (j < int(sqrt(i)))
	continue;
					  primeCnt++;
				}
			}
	}
	
	cout << "In the range of 1 to 10000, there are ";
	cout << primeCnt << " prime numbers, and there are ";
	cout << nonPrimeCnt <<" non-prime numbers." << endl; 
	
	return 0;  	
}
