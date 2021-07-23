// ***************************************************************
// primeNumber.cpp
// 将50～100之间的所有素数显示在标准输出设备上
// ***************************************************************
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   int i, j;
   bool isPrime;
   isPrime = true;
   for (i = 50; i < 100; i++){
	   for (j = 2 ; j <= int(sqrt(i)); j++){
		 if (i % j == 0) {
			isPrime = false;
			break;
		 }
	   }
	   if (isPrime)
		 cout << i << endl; 
	  isPrime = true;       
   }
   return 0;  	
}
